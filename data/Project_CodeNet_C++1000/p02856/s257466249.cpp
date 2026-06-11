#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl
#define show2(a, n, m) rep(i, n) { rep(j, m) {cout << a[i][j] << ' ';} cout << endl;} 
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

ll f(ll d, ll c, ll& ans) {
	if(c == 1) return d;
	ans += (1 + (d >= 5)) * (c / 2);
	ll d2 = (11 * d) % 9;
	if(d == 9) d2 = 9;
	ll ret = f(d2, c / 2, ans);
	if(c % 2) {
		ret += d;
		ans += 1 + (ret >= 10);
		if(ret >= 10) ret -= 9;
	}
	return ret;
}

int main() {
//	cout << fixed << setprecision(15);
	ll m;
	cin >> m;
	vll d(m), c(m);
	rep(i, m) cin >> d[i] >> c[i];

	ll ans = 0;
	rep(i, m) d[i] = f(d[i], c[i], ans);
	ll d2 = d[0];
	for(int i = 1; i < m; i++) {
		d2 += d[i];
		ans += 1 + (d2 >= 10);
		if(d2 >= 10) d2 -= 9;
	}
	cout << ans << endl;
}
