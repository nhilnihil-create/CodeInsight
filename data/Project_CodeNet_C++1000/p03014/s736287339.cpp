#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int main() { // 問題文はしっかり読め!!!
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}
	VV cx(h, V(w, -1));
	VV cy(h, V(w, -1));
	rep(i, h) {
		int cnt = 0;
		int pos = 0;
		rep(j, w) {
			if (s[i][j] == '.') cnt++;
			if (s[i][j] == '#' || j == w - 1) {
				if (j == w - 1) j++;
				REP(k, pos, j) {
					if (s[i][k] == '#') continue;
					cx[i][k] = cnt;
				}
				cnt = 0;
				pos = j;
			}
		}
	}
	rep(i, w) {
		int cnt = 0;
		int pos = 0;
		rep(j, h) {
			if (s[j][i] == '.') cnt++;
			if (s[j][i] == '#' || j == h - 1) {
				if (j == h - 1) j++;
				REP(k, pos, j) {
					if (s[k][i] == '#') continue;
					cy[k][i] = cnt;
				}
				cnt = 0;
				pos = j;
			}
		}
	}
	int ans = -1;
	rep(i, h) rep(j, w) {
		chmax(ans, cx[i][j] + cy[i][j] - 1);
	}
	cout << ans << endl;
	return 0;
}