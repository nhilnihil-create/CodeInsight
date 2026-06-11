#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {

	double r;
	cin >> r;

	//cout << r*r*M_PI << " " << 2*r*M_PI << endl;
	printf("%.6f %.6f", r*r*M_PI, 2*r*M_PI);
	cout << endl;

	return 0;
}