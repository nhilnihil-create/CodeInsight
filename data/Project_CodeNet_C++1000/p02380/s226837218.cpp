#include<stdio.h>//cでは三角関数の引数はラジアンを使わなければならない！
#include<math.h>
#define M_PI 3.14159265358979323846

int main(){
	int a,b,C;
	double c,L,h,S,rad;
	scanf("%d %d %d",&a,&b,&C);
	rad = C*M_PI/180;
	c = sqrt((a*a)+(b*b)-(2*a*b*cos(rad)));
	L = a+b+c;
	h = b*sin(rad);
	S = 0.5*h*a;
	printf("%f\n",S);
	printf("%f\n",L);
	printf("%f\n",h);
}