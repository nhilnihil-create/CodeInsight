#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define PI 3.14159265358979323

int main(int argc, char* argv[]) {
	double r;
	cin >> r;

	printf("%.5f %.5f", r * r * PI, 2 * r * PI);
	return 0;
}