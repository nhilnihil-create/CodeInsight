#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
	int i, n, x, y, r;
	double dis1 = 0; double dis2 = 0; double dis3 = 0;double disinf = 0;
	vector<int> X,Y,R;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x;
		X.push_back(x);
	}
	for (i = 0; i < n; i++) {
		cin >> y;
		Y.push_back(y);
	}
	for (i = 0; i < n; i++) {
		r = max(X[i] - Y[i],Y[i]-X[i]);
		R.push_back(r);
	}
	for (i = 0; i < n; i++) {
		dis1 += R[i];
		dis2 += pow(R[i], 2);
		dis3 += pow(R[i], 3);
		if (R[i] > disinf)disinf = R[i];
	}
	cout << fixed << setprecision(7) << dis1 << endl;
	cout << fixed << setprecision(7) << pow(dis2,0.5) << endl;
	cout << fixed << setprecision(7) << pow(dis3,double(1)/3) << endl;
	cout << fixed << setprecision(7) << disinf << endl;
	char t;
	cin >> t;
	return 0;
}
