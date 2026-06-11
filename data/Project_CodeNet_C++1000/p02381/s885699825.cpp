#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define FOR(i,a,b) for(size_t i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

typedef pair<ll, ll> pll;
// const ll INF = (ll)1e18;

bool solve() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	double a[n];
	double sum = 0;
	double sum2 = 0;
	REP (i, n) {
		cin >> a[i];
		sum += a[i];
	}
	double avg = sum / n;
	REP (i, n) {
		sum2 += pow(a[i] - avg, 2);
	}
	double res = sqrt(sum2 / n);
	cout << res << endl;
	return true;
}

signed main() {
	while (solve()) { }
}