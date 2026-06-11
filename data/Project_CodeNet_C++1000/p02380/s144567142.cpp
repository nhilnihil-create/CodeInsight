#include <cstdio>
#include <math.h>
using namespace std;


#define PI 3.141592653589793238462643383279
int a, b, c;

double rad(double d) {
	return PI * d / 180;
}
double sind(double c) {
	return sin(rad(c));
}
double cosd(double c) {
	return cos(rad(c));
}
double s() {
	return a*b*sind(c) / 2;
}
double l() {
	return a + b + sqrt(a*a + b*b - 2 * a*b*cosd(c));
}
double h() {
	return b*sind(c);
}
int main(){
	scanf("%d %d %d", &a, &b, &c);
	printf("%.5f\n%.5f\n%.5f\n", s(), l(), h());

	return 0;
}