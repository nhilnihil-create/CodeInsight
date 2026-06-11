#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>


#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define INF 1000000001
#define MOD 1000000007

const double pi = acos(-1);


using namespace std;


int main() {
	double a,b,r;
	cin >> a >> b >> r;
	r = r*pi / 180;
	double s = a*b*sin(r) / 2;
	double l = sqrt(a*a + b*b - 2 * a*b*cos(r))+a+b;
	double h = b*sin(r);
	cout <<setprecision(8)<< s <<" "<< l <<" "<< h << endl;
	

	return 0;
}