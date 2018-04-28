#ifndef __MIPI_TEST_H
#define __MIPI_TEST_H


const struct isp_reg_t test_mipi_system_control[] = {
	/*system control*/
	/*{0x60100, 0x01},*//*software standby*/
	/*{0x6301b, 0xf0},*//*clkrst*/

	{0x63025, 0x40},/*bypass config???*/

	{0x63106, 0x01},/*reserved*/
	{0x63107, 0xe0},/*reserved*/

	{0x63108, 0x04},/*fc input select mipi1*/
	/*isp input format:, for bypass
	 * 0x83: RAW8
	 * 0x87: RAW10
	 * 0x8b: RAW12
	 * 0x8f: RAW14
	 * 0x93: yuv422
	 * */
	/*{0x63022, 0x83},*//*isp input format, bypass mode*/
	{0x63022, 0x81},/*isp input format, bypass mode*/
	/*{0x63022, 0x85},*//*isp input format, bypass mode*/

	/*{0x63c21, 0x80},*//*pack1 en*/

	/*{0x6301a, 0x80},*//*enable emb clock*/

#if 0
	{0x63924, 0x00},
	{0x63925, 0x00},
	{0x63926, 0x00},
	{0x63927, 0x00},/*int config*/
	{0x63928, 0x00},
	{0x63929, 0x00},
	{0x6392a, 0x00},
	{0x6392b, 0x00},/*clear all interrupt*/
#endif
};

const struct isp_reg_t test_mipi_mac[] = {
	/*set mac format*/
	/*[7:4] w_dat_fmt_s1
	 *[3:0] w_dat_fmt_s0
	 *	bit3:3d_enable
	 *  bit2~0:
	 *	0:RAW8 | 1:RAW10 | 2:RAW 12 | 3:YUV422 | 4:NV12 | 5:RGB565 | 6:RGB888 | 7:YUV420
	 * */

	/**/
	{0x63b34,0x03}, //wformat NV12 NO 3D
	/*
	 * w_byte_switch
	 * [3][2]:switch2 switc1
	 *
	 * */
	/*{0x63b35,0x04}, //w_byte_switch*/
	/*{0x63b35,0x0c}, //w_byte_switch*/
	/*{0x63b35,0x08}, //w_byte_switch*/


	{0x63b36,0x02},
	{0x63b37,0x80}, //wimagewidth 640

	{0x63b38,0x02},
	{0x63b39,0x80}, //wmemwidth 640

	{0x63b3a,0x01},
	{0x63b3b,0xe0}, //wmemheight 480


	{0x63bb4,0x00},
	{0x63bb5,0x04},
	{0x63bb6,0xb0},
	{0x63bb7,0x00}, //wpixelnumber 640*480=307200=0x4b000

	/*prepare two frame buffer for nv12, one is for y, the other is for uv*/
	/*{0x63b30,0x03}, //wrdy0 == wrdy1 == 1*/
	/*{0x63b30,0x03}, */
	/*{0x63b30,0x03}, */

	/*{0x63b4d,0x77}, *//*for test purpose*/

	/*{0x63b53,0x03},*/
	/*{0x63b54,0xff}, //intrrupt enable*/
};
const struct isp_reg_t test_mipi_idi[] = {
	/* offset_1*/
	{0x63c00, 0x00},
	{0x63c01, 0x00},
	{0x63c02, 0x00},
	{0x63c03, 0x00},
	//size_1
	/*640 * 480*/
	{0x63c04, 0x02},
	{0x63c05, 0x80}, /*width:0x0280,640*/
	{0x63c06, 0x01},
	{0x63c07, 0xe0}, /*width:0x01e0,480*/
	//offset_2
	{0x63c08, 0x00},
	{0x63c09, 0x00},
	{0x63c0a, 0x00},
	{0x63c0b, 0x00},

	{0x63c04, 0x02},
	{0x63c05, 0x80}, /*width:0x0280,640*/
	{0x63c06, 0x01},
	{0x63c07, 0xe0}, /*width:0x01e0,480*/

	// line_length_1
	// 640
	{0x63c10, 0x02},
	{0x63c11, 0x80},

	// line_length_2
	{0x63c12, 0x02},
	{0x63c13, 0x80},
};

const struct isp_reg_t test_mipi_isp[] = {
	/*isp block control0~3*/
	/*{0x65000, 0x7e},*/
	{0x65000, 0x7f},
	{0x65001, 0xfb},
	/*{0x65001, 0xff},*/
	{0x65002, 0xe5},
	{0x65003, 0xef},

	/*reserved*/
	{0x65005, 0x10},

	/*test pattern*/
	/*{0x65007,0x20},*/

	/*BLC target*/
	{0x6500c, 0x00},
	{0x6500d, 0x10},

	/*ISP H input size*/
	{0x65010, 0x02},
	{0x65011, 0x80},
	/*ISP V input size*/
	{0x65012, 0x01},
	{0x65013, 0xe0},

	/*ISP output size1*/
	{0x65014, 0x02},
	{0x65015, 0x80},
	{0x65016, 0x01},
	{0x65017, 0xe0},

	/*isp_y_offset*/
	{0x6501a, 0x00},
	{0x6501b, 0x2b},

	/*reserved*/
	{0x65021, 0x00},

	/*scale up yscale*/
	{0x65026, 0x00},
	{0x65027, 0x80},

	/*scale up xscale*/
	{0x65028, 0x00},
	{0x65029, 0x80},

	/*isp ctrl2a*/
	{0x6502a, 0x40},
	/*isp ctrl2b*/
	{0x6502b, 0x9b},

	/*scale10*/
	{0x6502e, 0x40},

	/*scale down H outputsize*/
	{0x65032, 0x20},
	{0x65033, 0x80},
	/*scale down V outputsize*/
	{0x65034, 0x01},
	{0x65035, 0xe0},

	/*scale up x pos*/
	{0x65044, 0x01},
	{0x65045, 0xff},

	/*scale up y pos*/
	{0x65046, 0x00},
	{0x65047, 0x22},

	/*reserved,[1]scale_dual_en, [0],scaledn2_en*/
	{0x65050, 0x30},

	/*yuvdown2  h sizeout*/
	{0x65054, 0x02},
	{0x65055, 0x80},
	/*yuvdown2 v sizeout*/
	{0x65056, 0x01},
	{0x65057, 0xe0},

	/*ISP output size2*/
	{0x65058, 0x02},
	{0x65059, 0x80},
	{0x6505a, 0x01},
	{0x6505b, 0xe0},

	/*down2_xoffset*/
	{0x65062, 0x00},

	/*isp block ctrl63*/
	{0x65063, 0x0c},

	{0x6568e, 0x0b},

	/*idi,ctrl22,no_crop*/
	{0x63c22, 0x40},

	{0x67000, 0x01},
	{0x66700, 0x00},
	{0x66701, 0x00},
	{0x66702, 0x00},
	{0x66703, 0x00},
	{0x66704, 0x00},

	{0x65500, 0x04},
	{0x65501, 0x04},
	{0x65514, 0x61},

	{0x66304, 0x01},
	{0x66305, 0x7c},
	{0x6630c, 0x01},
	{0x6630d, 0xb8},

	{0x66314, 0x00},
	{0x66315, 0x00},
	{0x66316, 0x00},
	{0x66317, 0x00},
	{0x66318, 0x00},

	{0x67101, 0x60},

	{0x65b00, 0x00},
	{0x65b01, 0x00},
	{0x65b02, 0x00},
	{0x65b03, 0x00},
	{0x65b04, 0x00},
	{0x65b05, 0x00},
	{0x65b06, 0x00},
	{0x65b07, 0x00},
	{0x65b08, 0x00},
	{0x65b09, 0x00},
	{0x65b0a, 0x00},
	{0x65b0b, 0x00},

	{0x6508a, 0x13},
	{0x65089, 0x09},

	{0x66c44, 0x00},

	{0x66c45, 0x00},

	{0x66c46, 0x00},

	{0x66c47, 0x00},

	{0x66c48, 0x00},

	{0x66c49, 0x00},

	{0x66c4a, 0x00},

	{0x66c4b, 0x00},

	{0x66c4c, 0x00},

	{0x66c4d, 0x00},

	{0x66c4e, 0x00},

	{0x66c4f, 0x00},

	{0x66c50, 0x00},

	{0x66c51, 0x00},

	{0x66c52, 0x00},

	{0x66c53, 0x00},

	{0x66c54, 0x00},

	{0x66c55, 0x00},

	{0x66c56, 0x00},

	{0x66c57, 0x00},

	{0x66c58, 0x00},

	{0x66c59, 0x00},

	{0x66c5a, 0x00},

	{0x66c5b, 0x00},

	{0x66c5c, 0x00},

	{0x66c5d, 0x00},

	{0x66c5e, 0x00},

	{0x66c5f, 0x00},

	{0x66c60, 0x00},

	{0x66c61, 0x00},

	{0x66c62, 0x00},

	{0x66c63, 0x00},

	{0x66c64, 0x00},

	{0x66c65, 0x00},

	{0x66c66, 0x00},

	{0x66c67, 0x00},

	{0x66c68, 0x00},

	{0x66c69, 0x00},

	{0x66c6a, 0x00},

	{0x66c6b, 0x00},

	{0x66c6c, 0x00},

	{0x66c6d, 0x00},

	{0x66c6e, 0x00},

	{0x66c6f, 0x00},

	{0x66c70, 0x00},

	{0x66c71, 0x00},

	{0x66c72, 0x00},

	{0x66c73, 0x00},

	{0x66c74, 0x00},

	{0x66c75, 0x00},

	{0x66c76, 0x00},

	{0x66c77, 0x00},

	{0x66c78, 0x00},

	{0x66c79, 0x00},

	{0x66c7a, 0x00},

	{0x66c7b, 0x00},

	{0x66c7c, 0x00},

	{0x66c7d, 0x00},

	{0x66c7e, 0x00},

	{0x66c7f, 0x00},

	{0x66c80, 0x00},

	{0x66c81, 0x00},

	{0x66c82, 0x00},

	{0x66c83, 0x00},

	{0x66c84, 0x00},

	{0x66c85, 0x00},

	{0x66c86, 0x00},

	{0x66c87, 0x00},

	{0x66c88, 0x00},

	{0x66c89, 0x00},

	{0x66c8a, 0x00},

	{0x66c8b, 0x00},

	{0x66c8c, 0x00},

	{0x66c8d, 0x00},

	{0x66c8e, 0x00},

	{0x66c8f, 0x00},

	{0x66c90, 0x00},

	{0x66c91, 0x00},

	{0x66c92, 0x00},

	{0x66c93, 0x00},

	{0x66c94, 0x00},

	{0x66c95, 0x00},

	{0x66c96, 0x00},

	{0x66c97, 0x00},

	{0x66c98, 0x00},

	{0x66c99, 0x00},

	{0x66c9a, 0x00},

	{0x66c9b, 0x00},

	{0x66c9c, 0x00},

	{0x66c9d, 0x00},

	{0x66c9e, 0x00},

	{0x66c9f, 0x00},

	{0x66ca0, 0x00},

	{0x66ca1, 0x00},

	{0x66ca2, 0x00},

	{0x66ca3, 0x00},

	{0x66ca4, 0x00},

	{0x66ca5, 0x00},

	{0x66ca6, 0x00},

	{0x66ca7, 0x00},

	{0x66ca8, 0x00},

	{0x66ca9, 0x00},

	{0x66caa, 0x00},

	{0x66cab, 0x00},

	{0x66cac, 0x00},

	{0x66cad, 0x00},

	{0x66cae, 0x00},

	{0x66caf, 0x00},

	{0x66cb0, 0x00},

	{0x66cb1, 0x00},

	{0x66cb2, 0x00},

	{0x66cb3, 0x00},

	{0x66cb4, 0x00},

	{0x66cb5, 0x00},

	{0x66cb6, 0x00},

	{0x66cb7, 0x00},

	{0x66cb8, 0x00},

	{0x66cb9, 0x00},

	{0x66cba, 0x00},

	{0x66cbb, 0x00},

	{0x66cbc, 0x00},

	{0x66cbd, 0x00},

	{0x66cbe, 0x00},

	{0x66cbf, 0x00},

	{0x66cc0, 0x00},

	{0x66cc1, 0x00},

	{0x66cc2, 0x00},

	{0x66cc3, 0x00},

	{0x66cc4, 0x40},

	{0x65218, 0x04},
	{0x65219, 0x34},
	{0x6521a, 0x04},
	{0x6521b, 0x3c},
	{0x6521c, 0x04},
	{0x6521d, 0x44},
	{0x6521e, 0x04},
	{0x6521f, 0x4c},

	{0x65320, 0x01},
	{0x65407, 0x01},
	{0x65408, 0x04},
	{0x65612, 0x00},
	{0x65613, 0x10},
	{0x6590d, 0x00},
	{0x66501, 0x00},
	{0x66502, 0x08},
	{0x66503, 0x00},
	{0x66504, 0x08},
	{0x66505, 0x00},
	{0x66506, 0x08},
	{0x66507, 0x00},
	{0x66508, 0x10},
	{0x66509, 0x00},
	{0x6650a, 0x20},
	{0x6650b, 0x00},
	{0x6650c, 0x20},
	{0x6650d, 0x00},
	{0x6650e, 0x40},
	{0x6650f, 0x00},
	{0x66510, 0x40},
	{0x66529, 0x10},
	{0x6652a, 0x10},
	{0x6652c, 0x06},
	{0x6652f, 0x04},
	{0x66530, 0x04},
	{0x66531, 0x08},

	/*yuv cropwidth for channel1*/
	/*crop area, 640 * 480*/
	{0x650f4, 0x02},
	{0x650f5, 0x80},
	{0x650f6, 0x01},
	{0x650f7, 0xe0},
	/*yuv cropwidth for channel2*/
	/*crop area, 640 * 480*/
	{0x66204, 0x02},
	{0x66205, 0x80},
	{0x66206, 0x01},
	{0x66207, 0xe0},

	/*crop64_x_end, crop64_y_end*/
	{0x65069, 0x02},
	{0x6506a, 0x80},
	{0x6506b, 0x01},
	{0x6506c, 0xe0},

	/*UV DNS register*/
	{0x66100, 0x01},
	{0x66101, 0x02},
	{0x66102, 0x04},
	{0x66103, 0x08},
	{0x66104, 0x0c},
	{0x66105, 0x10},
	{0x66106, 0x46},

	{0x65d01, 0x01},
	{0x65d02, 0x02},
	{0x65d03, 0x03},
	{0x65d04, 0x04},
	{0x65d05, 0x04},
	{0x65d06, 0x04},
	{0x65d07, 0x04},
};



#endif