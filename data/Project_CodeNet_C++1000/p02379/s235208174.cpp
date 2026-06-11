#include <stdio.h>



#ifndef DEBUG 
#define fprintf (void)
#endif 

double absval(double x);

int main(void){

	double x1,y1,x2,y2;
	double b=0;
	int n;
	scanf("%lf", &x1);
	scanf("%lf", &y1);
	scanf("%lf", &x2);
	scanf("%lf", &y2);
	double dx=absval(x1-x2);
	double dy=absval(y1-y2);
	
	double x=dx*dx+dy*dy;
	fprintf(stdout,"%lf\n",x);
	
	scanf("%d",&n);
	
	while(b*b<x){
		b++;
	}
	while(absval(b*b-x)>0.0001){
		b=(b*b+x)/(2*b);
		fprintf(stdout,"%f\n",b);
	}	
	printf("%f\n", b);
	
	return 0;
}

double absval(double x){
	if(x<0){
		return -x;
	}else{
		return x;
	}
}