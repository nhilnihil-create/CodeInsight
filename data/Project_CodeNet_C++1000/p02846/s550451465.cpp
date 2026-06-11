#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define _USE_MATH_DEFINES
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
double mysqrt(double x) {
	double l = 0, r = x;
	for (int i = 0; i < 64; ++i) {
		double m = (l + r) / 2.0;
		if (m*m < x)l = m;
		else r = m;
	}
	return l;
}
///////////////////////////////////////


int main() {
	ll T[2];
	ll A[2], B[2];
	REP(i, 2)cin >> T[i];
	REP(i, 2)cin >> A[i];
	REP(i, 2)cin >> B[i];
	A[0] *= T[0];
	B[0] *= T[0];
	A[1] *= T[1];
	B[1] *= T[1];
	ll P = A[0] - B[0];
	ll S = A[0] + A[1] - B[0] - B[1];
	if ((P > 0 && A[0] + A[1] > B[0] + B[1]) || (P < 0 && B[0] + B[1] > A[0] + A[1])) {
		cout << 0 << endl;
	}
	else if (S == 0) {
		cout << "infinity" << endl;
	}
	else {
		if (P > 0) {
			S *= -1;
			if (P % S == 0) {
				cout << 2 * ll(P / S) << endl;
			}
			else {
				cout<< 1+ll(P/S)*2 << endl;
			}
		}
		else {
			P *= -1;
			if (P % S== 0) {
				cout << 2 * ll(P / S) << endl;
			}
			else {
				cout << 1 + ll(P / S)*2 << endl;
			}
		}
	}
}