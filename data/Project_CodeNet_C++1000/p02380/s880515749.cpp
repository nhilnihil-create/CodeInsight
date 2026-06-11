#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define FOR(i,a,b) for(long long int i=(a);i<(b);i++)
#define REP(i,n) for(long long int i=0;i<(n);i++)

#define PI 3.14159265358479

double l(long double a, long double b, long double C){
	return a + b + powl(powl(a - b*cos(C / 180.0*PI), 2.0) + powl(b*sin(C / 180.0*PI), 2.0), 0.5);
}

int main(){
	long double a, b, C;
	cin >> a >> b >> C;
	cout << fixed << 0.5*a*b*sin(C / 180.0*PI) << "\n" << l(a, b, C) << "\n" << b*sin(C / 180.0*PI) << "\n";
	return 0;
}