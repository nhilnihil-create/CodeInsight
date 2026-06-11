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


ll N;
ll D[100010];
ll cnt[100010];
ll key = 0;
int main() {
	cin >> N;
	REP(i, N) {
		cin >> D[i];
		if (i != 0 && D[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
		cnt[D[i]]++;
		key = max(key, D[i]);
	}
	if (cnt[0] != 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	for (ll i = 2; i <=key; ++i) {
		if (i != key && cnt[i] == 0)ans = 0;
		else {
			ll x = cnt[i];
			while (x != 0) {
				ans *= cnt[i - 1];
				ans %= 998244353;
				x--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}