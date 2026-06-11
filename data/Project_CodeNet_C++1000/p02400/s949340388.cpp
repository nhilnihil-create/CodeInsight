#include <cstdio>
#include <cmath>

int main(void){
	double r=1;

	std::scanf("%lf",&r);
	std::printf("%lf %lf\n",std::pow(r,2)*M_PI,2*r*M_PI);
	return 0;
}