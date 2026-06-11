#include <bits/stdc++.h>
using namespace std;

void kochCurve(int n, pair<double, double> s, pair<double, double> e){
	if(n == 0) return;

	pair<double, double> l, r, m;
	l.first = (2.0 * s.first + e.first) / 3.0;
	l.second = (2.0 * s.second + e.second) / 3.0;
	r.first = (s.first + 2.0 * e.first) / 3.0;
	r.second = (s.second + 2.0 * e.second) / 3.0;
	m.first = (r.first - l.first) / 2.0 - (r.second - l.second) * sin(acos(-1.0)/3.0) + l.first;
	m.second = (r.first - l.first) * sin(acos(-1.0)/3.0) + (r.second - l.second) / 2.0 + l.second;

	kochCurve(n-1, s, l);
	printf("%.12lf %.12lf\n", l.first,  l.second);
	kochCurve(n-1, l, m);
	printf("%.12lf %.12lf\n", m.first,  m.second);
	kochCurve(n-1, m, r);
	printf("%.12lf %.12lf\n", r.first,  r.second);
	kochCurve(n-1, r, e);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%.12lf %.12lf\n", 0.0, 0.0);
	kochCurve(n, make_pair(0.0, 0.0), make_pair(100.0, 0.0));
	printf("%.12lf %.12lf\n", 100.0, 0.0);
}

