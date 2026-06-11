#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c,h;
	
	scanf("%lf %lf %lf",&a,&b,&c);
	
	h=b*sin(M_PI*c/180);
	
	printf("%f\n",a*h/2);
	printf("%f\n",a+b+sqrt(( a-(b*cos(M_PI*c/180)) )*( a-(b*cos(M_PI*c/180)) )+h*h));
	printf("%f\n",h);
	
	return 0;
}