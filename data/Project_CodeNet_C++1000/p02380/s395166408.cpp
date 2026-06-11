#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cctype>
#include<string.h>

#define PI 3.1415926

int main(){
	int a, b,c;
	double	C, S, L, h;
	scanf("%d %d %d", &a, &b, &c);

	C =c *PI / 180;

	S = (a*b*sin(C)) / 2;
	L = a + b + sqrt(a*a + b*b - 2 * a*b*cos(C));
	h = b*sin(C);

	printf("%f\n%f\n%f\n", S, L, h);
	
	return 0;
}