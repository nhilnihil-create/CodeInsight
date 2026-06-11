#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<double, double> vec2;

vec2 operator-(const vec2& lhs, const vec2& rhs) {
	vec2 r;
	r.first = lhs.first - rhs.first;
	r.second = lhs.second - rhs.second;
	return r;
}

vec2 operator*(const vec2& lhs, const double rhs) {
	vec2 r;
	r.first = lhs.first * rhs;
	r.second = lhs.second * rhs;
	return r;
}



int n;

void koch(vec2 start, vec2 end, int i) {
	if (i == n) return;

	vec2 s = { (2 * start.first + 1 * end.first) / 3, 
			   (2 * start.second + 1 * end.second) / 3};
	vec2 t = { (1 * start.first + 2 * end.first) / 3,
			   (1 * start.second + 2 * end.second) / 3};
	
	vec2 ts = t - s;
	double rad = M_PI * 60.0 / 180.0;
	vec2 u = {
		ts.first * cos(rad) - ts.second * sin(rad) + s.first,
		ts.first * sin(rad) + ts.second * cos(rad) + s.second,
	};

	koch(start, s, i + 1);

	printf("%.8f  %.8f\n", s.first, s.second);
	koch(s, u, i + 1);

	printf("%.8f  %.8f\n", u.first, u.second);
	koch(u, t, i + 1);

	printf("%.8f  %.8f\n", t.first, t.second);
	koch(t, end, i + 1);



}

int main() {
	cin >> n;

	vec2 start = { 0.0f, 0.0f };
	vec2 end = { 100.0f, 0.0f };

	printf("%.8f  %.8f\n", start.first, start.second);
	koch(start, end, 0);
	printf("%.8f  %.8f\n", end.first, end.second);


	return 0;
}
