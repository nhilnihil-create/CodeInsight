#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void koch(pair<double, double> p1, pair<double, double> p2, long n){
	if (n == 0) return;
	pair<double, double> s, u, t;
	s.first = (p1.first * 2 + p2.first) / 3;
	s.second = (p1.second * 2 + p2.second) / 3;
	t.first = (p1.first + p2.first * 2) / 3;
	t.second = (p1.second + p2.second * 2) / 3;
	u.first = 0.5 * t.first - 0.5 * sqrt(3) * t.second + 0.5 * s.first + 0.5 * sqrt(3) * s.second;
	u.second = 0.5 * sqrt(3) * t.first + 0.5 * t.second - 0.5 * sqrt(3) * s.first + 0.5 * s.second;
	koch(p1, s, n - 1);
	cout << s.first << " " << s.second << endl;
	koch(s, u, n - 1);
	cout << u.first << " " << u.second << endl;
	koch(u, t, n - 1);
	cout << t.first << " " << t.second << endl;
	koch(t, p2, n - 1);
}

int main(){
	long n;
	cin >> n;
	pair<double, double> p1, p2;
	p1.first = 0; p1.second = 0;
	p2.first = 100; p2.second = 0;
	cout << setprecision(10) << p1.first << " " << p1.second << endl;
	koch(p1, p2, n);
	cout << p2.first << " " << p2.second << endl;
	return 0;
}