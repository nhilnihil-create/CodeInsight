#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

double PI = 3.14159265358979;
double A, B, H, M, c1, c2;

int main() {
	cin >> A >> B >> H >> M;
	c1 = (60.0 * H + M) / 720.0;
	c2 = M / 60.0;

	double sx = A * cos(2.0 * c1 * PI), sy = A * sin(2.0 * c1 * PI);
	double tx = B * cos(2.0 * c2 * PI), ty = B * sin(2.0 * c2 * PI);
	double ans = sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));
	printf("%.12lf\n", ans);
	return 0;
}