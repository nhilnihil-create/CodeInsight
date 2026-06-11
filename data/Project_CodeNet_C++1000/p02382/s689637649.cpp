#include<iostream>
#include<cmath>
#include<iomanip>
#include<cfloat>
#include<algorithm>
using namespace std;

int n, i;

double minkdis(double x[], double y[], double p);

int main() {
	double x[100], y[100];
	cin >> n;
	for (i = 0; i < n; i++)cin >> x[i];
	for (i = 0; i < n; i++)cin >> y[i];
	cout << setprecision(10) << minkdis(x, y, 1) << endl << minkdis(x, y, 2) << endl 
		<< minkdis(x, y, 3) << endl << minkdis(x, y, DBL_MAX) << endl;
	return 0;
}

double minkdis(double x[], double y[], double p) {
	double dis = 0;
	if (p == DBL_MAX) {
		double maxd = fabs(x[0] - y[0]);
		for (i = 1; i < n; i++) {
			maxd = max(maxd, fabs(x[i] - y[i]));
		}
		return maxd;
	}
	for (i = 0; i < n; i++) {
		dis += pow(fabs(x[i] - y[i]), p);
	}
	return pow(dis, 1 / p);
}