#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define FOR(i,a,b) for(long long int i=(a);i<(b);i++)
#define REP(i,n) for(long long int i=0;i<(n);i++)

int main(){
	long double x1,x2,y1,y2,d;
	cin >> x1 >> y1 >> x2 >> y2;
	d = powl(powl(x1 - x2, 2.0) + powl(y1 - y2, 2.0), 0.5);
	cout << fixed << d << "\n";
	return 0;
}