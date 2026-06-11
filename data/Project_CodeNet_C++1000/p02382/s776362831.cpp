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

int main(){
	int n;
	vector<double> x, y, z;
	double d1 = 0, d2 = 0, d3 = 0, d = 0;
	cin >> n;
	REP(i, n){
		double dx;
		cin >> dx;
		x.push_back(dx);
	}
	REP(i, n){
		double dy;
		cin >> dy;
		y.push_back(dy);
	}

	REP(i, n){
		z.push_back(x[i] - y[i]);
		if (z[i] < 0)z[i] = -z[i];
		d1 += z[i];
	} 
	z.clear();

	REP(i, n){
		z.push_back(x[i] - y[i]);
		if (z[i] < 0)z[i] = -z[i];
		z[i] = powl(z[i], 2.0);
		d2 += z[i];
	}
	d2 = powl(d2, 0.5);
	z.clear();

	REP(i, n){
		z.push_back(x[i] - y[i]);
		if (z[i] < 0)z[i] = -z[i];
		z[i] = powl(z[i], 3.0);
		d3 += z[i];
	}
	d3 = powl(d3, 0.33333333333333333333333);
	z.clear();

	REP(i, n){
		z.push_back(x[i] - y[i]);
		if (z[i] < 0)z[i] = -z[i];
		if (d < z[i])d = z[i];
	}
	z.clear();

	cout << fixed << d1 << "\n" << d2 << "\n" << d3 << "\n" << d << "\n";
	return 0;
}