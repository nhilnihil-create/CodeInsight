#include<stdio.h>
using namespace std;

double r = 0.0;
double a = 0.0, b = 0.0;


int main() {

	scanf("%lf", &r);
	//面積
	a = r * r * 3.141592653589;
	//円周
	b = r * 2 * 3.141592653589;

	printf("%f %f\n",a,b);

		return 0;
}


