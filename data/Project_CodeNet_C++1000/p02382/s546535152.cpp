#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int main() {
	int n, x[110], y[110];
	cin >> n;
	rep(i,n) {
		cin >> x[i];
	}
	rep(i,n) {
		cin >> y[i];
	}
	double ret = 0.0;
	rep(i,n) {
		ret += abs(x[i] - y[i]);
	}
	printf("%.10lf\n", ret);
	ret = 0.0;
	rep(i,n) {
		ret += pow(x[i] - y[i], 2.0);
	}
	printf("%.10lf\n", sqrt(ret));
	ret = 0.0;
	rep(i,n) {
		ret += abs(pow(x[i] - y[i], 3.0));
	}
	printf("%.10lf\n", pow(ret, 1.0 / 3.0));
	ret = 0.0;
	rep(i,n) {
		if(ret < abs(x[i] - y[i])) ret = abs(x[i] - y[i]);
	}
	printf("%.10lf\n", ret);
	return 0;
}
	