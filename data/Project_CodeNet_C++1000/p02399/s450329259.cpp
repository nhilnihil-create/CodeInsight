#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int a, b;
	double da, db;
	cin >> a >> b;
	int d = a / b;
	int r = a % b;
	da = (double)a;
	db = (double)b;
	double f = da / db;
	printf("%d %d %.8lf\n", d, r, f);
	return 0;
}