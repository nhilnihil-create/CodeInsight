#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	string s, t;
	cin >> s >> t;
	vector<vector<int>> v(26);
	int n = s.size();
	s += s;
	rep(i,s.size()) {
		v[s[i] - 'a'].push_back(i);
	}
	int p = -1;
	ll x = 0;
	rep(i,t.size()) {
		int k = t[i] - 'a';
		if (!v[k].size()) {
			cout << -1 << endl;
			return 0;
		}
		p = v[k][upper_bound(v[k].begin(), v[k].end(), p) - v[k].begin()];
		if (p >= n) {
			x++;
			p %= n;
		}
	}
	cout << n * x + p + 1 << endl;
}