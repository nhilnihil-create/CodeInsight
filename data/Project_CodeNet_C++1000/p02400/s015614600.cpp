#include<iostream>
using namespace std;

int main() {
	double r;
	double pi=3.14159265358979, s, l;
	cin >> r;
	s = pi*r*r;
	l = 2*pi*r;
	cout << fixed << s << ' ' << fixed << l << endl;
}