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

int n, m, q;
vector<int> a, b, c, d;

int dfs(vector<int> v) {
	if (v.size() == n) {
		int res = 0;
		rep(i, q) {
			if (v[b[i]] - v[a[i]] == c[i])  {
				res += d[i];
			}
		}
		return res;
	}
	int res = 0;
	for (int i = v[v.size()-1]; i <= m; i++) {
		vector<int> u = v;
		u.push_back(i);
		res = max(res, dfs(u));
	}
	return res;
}


int main() {
	cin >> n >> m >> q;
	a.resize(q);
	b.resize(q);
	c.resize(q);
	d.resize(q);
	rep(i,q) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--, b[i]--;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		vector<int> v(1, i);
		ans = max(dfs(v), ans);
	}
	cout << ans << endl;
}