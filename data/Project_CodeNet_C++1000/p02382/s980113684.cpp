#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>
#include<functional>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265358979

using namespace std;
typedef pair<int, int> P;

int main(void) {
	int n;
	double x[101], y[101];
	double max = 0;
	double m1 = 0, m2 = 0, m3 = 0, mi = 0;

	cin >> n;
	FOR(i, 1, n) {
		cin >> x[i];
	}
	FOR(i, 1, n) {
		cin >> y[i];
	}
	FOR(i, 1, n) {
		m1 += pow(abs(x[i] - y[i]), 1);
		m2 += pow(abs(x[i] - y[i]), 2);
		m3 += pow(abs(x[i] - y[i]), 3);
		if (abs(x[i] - y[i]) > max) {
			max = abs(x[i] - y[i]);
		}
	}
	m2 = sqrt(m2);
	m3 = cbrt(m3);
	mi = max;

	printf("%.10lf\n", m1);
	printf("%.10lf\n", m2);
	printf("%.10lf\n", m3);
	printf("%.10lf\n", mi);
	return 0;
}
