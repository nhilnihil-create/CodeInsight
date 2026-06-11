#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){

	double a, b, c, C, PI=3.1415926535;;
	double S, L, h;

	cin >> a >> b >> C;

	/* 面積の計算（三角比の高さを求める式）*/
	S = a * b * sin(C*PI/180) / 2;

	/* 周の長さ（余弦定理で未知の辺の長さを求める）*/
	c = sqrt(pow(a,2)+pow(b,2) - 2*a*b*cos(PI*C/180));
	L = a + b + c;

	/* 辺aが底辺のときの長さ（三角比の高さを求める式） */
	h = b * sin(PI*C/180);

	printf("%.8f\n", S);
	printf("%.8f\n", L);
	printf("%.8f\n", h);


	return 0;
}

/************************************************************/
//
// cos(double x)とsin(double x)を使うときの注意点
// （ カッコ内の変数 ）はラジアンを代入すること
//  1° = π/180
//  例：90°のときは　⇒　90°= 90 × π/180
//                    ⇒  90°= π/2
//                    ⇒  答え: π/2
//
/***********************************************************/
