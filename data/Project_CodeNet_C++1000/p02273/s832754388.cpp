#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265359
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
typedef long long ll;
using namespace std;

void koch(int d,pair<double,double> p1,pair<double,double> p2) {
	if (d == 0) return;

	pair<double,double> s, t, u;
	s.first = (p1.first*2 + p2.first) / 3.0000000;
	s.second = (p1.second * 2 + p2.second) / 3.0000000;
	t.first = (p2.first * 2 + p1.first) / 3.0000000;
	t.second = (p2.second * 2 + p1.second) / 3.0000000;
	u.first = s.first + (t.first - s.first)*cos(PI / 3) + (-t.second + s.second)*sin(PI / 3);
	u.second = s.second + (t.second - s.second)*cos(PI / 3) + (t.first - s.first)*sin(PI / 3);

	koch(d - 1, p1, s);
	cout << s.first << " " << s.second << endl;
	koch(d - 1, s, u);
	cout << u.first << " " << u.second << endl;
	koch(d - 1, u, t);
	cout << t.first << " " << t.second << endl;
	koch(d - 1, t, p2);
}

int main() {
	int n;
	pair<double, double> p1, p2;
	p1.first = p1.second = p2.second = 0.0000000;
	p2.first = 100.0000000;
	cin >> n;
	cout << p1.first << " " << p1.second << endl;
	koch(n,p1,p2);
	cout << p2.first << " " << p2.second << endl;
	return 0;
}