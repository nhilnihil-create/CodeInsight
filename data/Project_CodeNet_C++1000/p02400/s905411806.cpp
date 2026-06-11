#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	double r;
	double menseki, enshu;

	cin >> r;

	menseki = 3.141592653589*r*r;
	enshu = 2 * 3.141592653589*r;

	printf("%.6lf %.6lf\n", menseki, enshu);

	return 0;

}