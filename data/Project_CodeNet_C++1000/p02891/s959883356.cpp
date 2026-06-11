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

ll f(string s) {
	ll N = sz(s);
	ll sum = 0;
	for (ll i = 0, j = 0; i < N; i = j) {
		while (j < N && s[i] == s[j]) {
			j++;
		}
		sum += (j - i) / 2;
	}
	return sum;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	string s;
	cin >> s;
	ll N = sz(s);
	ll k;
	cin >> k;

	bool same = true;
	rep(i, N) {
		if (s[0] != s[i]) {
			same = false;
		}
	}
	if (same) {
		out((N * k) / 2);
		return 0;
	}

	ll d1 = f(s);
	ll d2 = f(s + s);

	ll a = d1;		//s一コ分
	ll d = d2 - d1;	//増えた分(差分)がk-1コ

	cout << a + d * (k - 1)<< endl;

	return 0;
}