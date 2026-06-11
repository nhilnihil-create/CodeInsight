#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define dup(x,y) (((x)+(y)-1)/(y))
#define sz(x) int(x.size())
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	string s, t;
	cin >> s >> t;
	set<char>se;
	for (auto i : s)se.insert(i);
	for (auto i : t) {
		if (!se.count(i)) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<vector<int>>v(26);
	rep(i, s.size()) {
		int n = (int)s[i] - (int)'a';
		v[n].push_back(i + 1);
	}
	rep(i, s.size()) {
		int n = (int)s[i] - (int)'a';
		v[n].push_back(i + 1 + s.size());
	}

	int ans = 0;
	int pre = 0;
	int SLEN = s.size();
	int TLEN = t.size();
	rep(i, TLEN) {
		int n = (int)t[i] - (int)'a';
		int now = *lower_bound(v[n].begin(), v[n].end(), pre + 1);
		ans += now - pre;
		if (now > SLEN)pre = now - SLEN;
		else pre = now;
	}
	cout << ans << endl;
}