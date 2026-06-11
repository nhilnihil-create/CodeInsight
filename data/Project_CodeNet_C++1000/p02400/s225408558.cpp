#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double r;
	cin >> r;
	double p = acos(-1);;
	printf("%.10lf ", r * r * p);
	printf("%.10lf\n", 2 * r * p);
	return 0;
}