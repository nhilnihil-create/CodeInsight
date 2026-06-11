#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

double x[100], y[100];
int main() {
	int n; cin >> n;
	rep(i, n)cin >> x[i];
	rep(i, n)cin >> y[i];
	double a = 0, b = 0, c = 0, d = 0;
	rep(i, n)a += abs(x[i] - y[i]);
	rep(i, n)b += abs(x[i] - y[i])*abs(x[i] - y[i]);
	b = sqrt(b);
	rep(i, n)d += abs(x[i] - y[i])*abs(x[i] - y[i])*abs(x[i] - y[i]);
	d = cbrt(d);
	rep(i, n)c = max(c, abs(x[i] - y[i]));
	printf("%.7lf\n%.7lf\n%.7lf\n%.7lf\n", a, b, d, c);
}