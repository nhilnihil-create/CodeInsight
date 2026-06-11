#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

int main() {
	double r; cin >> r;
	printf("%.10f %.10f", (r * r * M_PI), (2 * M_PI * r));
}