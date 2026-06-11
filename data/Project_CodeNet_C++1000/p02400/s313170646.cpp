#include<cstdio>

int main(){
	double r;
	double p = 3.141592653589;
	scanf("%lf", &r);
	double S = p*r*r;
	double L = 2*p*r;
	printf("%f %f\n", S, L);

	return 0;
}