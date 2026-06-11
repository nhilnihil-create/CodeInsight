#include<stdio.h>
int main(){
	double menseki,enshu,r;
	double PI=3.141592653589;
	scanf("%lf",&r);
	menseki=PI*r*r;
	enshu=2*PI*r;
	printf("%f %f\n",menseki,enshu);
	return 0;
}