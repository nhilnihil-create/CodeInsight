#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const double PI = acos(-1);

//dp[i][j] : 
//先頭i文字として考えられるのものうち,
//13で割った余りがjであるもの.
ll dp[MAX_N][13];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	string s;
	cin >> s;

	dp[0][0] = 1;

	for (int i = 0; i < sz(s); i++) {
		int c;
		if (s[i] == '?') {
			c = -1;
		}
		else {
			c = s[i] - '0';
		}

		//数字を新しく右にくっつけていくことを考える.
		for (int j = 0; j < 10; j++) {
			if (c == -1 || c == j) {
				//前には0~12のどれかがあるはずなので全通り試す.
				for (int k = 0; k < 13; k++) {
					dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
				}
			}
		}
		for (int j = 0; j < 13; j++) {
			dp[i + 1][j] %= mod;
		}
	}

	out(dp[sz(s)][5]);

	return 0;
}