#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

static const ll INF = 1e15;

static const ll mod = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> ds(n);
	rep(i, n) {
		ds[i] = s[i] - '0';
	}
	vector<vector<ll>> dp;
	dp.assign(n, vector<ll>(13, 0));
	if (s[0] == '?') {
		rep(i, 10) {
			dp[0][i] = 1;
		}
	}
	else {
		dp[0][ds[0]] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == '?') {
			rep(k, 10) {
				rep(j, 13) {
					auto num = dp[i - 1][j];
					ll m = j * 10 + k;
					m %= 13;
					dp[i][m] += num;
					dp[i][m] %= mod;
				}
			}
		}
		else {
			rep(j, 13) {
				auto num = dp[i - 1][j];
				ll m = j * 10 + ds[i];
				m %= 13;
				dp[i][m] += num;
				dp[i][m] %= mod;
			}
		}
	}
	cout << dp[n - 1][5] << endl;
	return 0;
}
	