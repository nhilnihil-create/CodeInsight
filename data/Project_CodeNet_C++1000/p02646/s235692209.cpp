#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;
	if (v <= w) {
		cout << "NO" << endl;
		return 0;
	}
	if (a < 0 || b < 0) {
		a += 1e9;
		b += 1e9;
	}
	long double dist = abs(a - b);
	long double run = v - w;
	if ((dist/t) <= run) {
		cout << "YES" << endl;
		return 0;
	}
	else {
		cout << "NO" << endl;
		return 0;
	}
	return 0;
}

