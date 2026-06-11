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
const long double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n;
	cin >> n;
	string s;
	cin >> s;

	int res = 0;
	//dp[i][j]: i文字目からとj文字目からとで最長の長さ(被りもok)
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (s[i] == s[j]) {
				chmax(dp[i][j], dp[i + 1][j + 1] + 1);
			}
			chmax(res, min(dp[i][j], j - i));
		}
	}
	
	out(res);

	return 0;
}