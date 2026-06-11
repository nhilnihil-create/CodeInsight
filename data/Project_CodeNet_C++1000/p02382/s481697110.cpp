#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

int main() {
	cout << fixed << setprecision(6);
	double D[4] = {}, x[100], y[100];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	for (int i = 0; i < n; i++) {
		D[1] += fabs(x[i] - y[i]);
	}
	for (int i = 0; i < n; i++) {
		D[2] += fabs(x[i] - y[i])*fabs(x[i] - y[i]);
	}
	D[2] = sqrt(D[2]);
	for (int i = 0; i < n; i++) {
		D[3] += fabs(x[i] - y[i])*fabs(x[i] - y[i])*fabs(x[i] - y[i]);
	}
	D[3] = pow(D[3], 1. / 3);
	for (int i = 0; i < n; i++) {
		D[0] = max(D[0], fabs(x[i] - y[i]));
	}
	cout << D[1] << endl;
	cout << D[2] << endl;
	cout << D[3] << endl;
	cout << D[0] << endl;
	return 0;
}