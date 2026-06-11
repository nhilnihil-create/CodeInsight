#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<int>> to;

void solve() {
	int n;
	cin >> n;
	to.resize(n);
	vector<pii> v(n-1);
	rep(i,n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[i] = make_pair(a, b);
		to[a].push_back(b);
		to[b].push_back(a);
	}
	int mx = 0;
	rep(i,n) mx = max(mx, (int)to[i].size());
	map<pii, int> mp;
	queue<pair<pii, int>> q;
	int prev = 0;
	q.push(make_pair(make_pair(-1, 0), -1));
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		int s = p.first.first;
		int t = p.first.second;
		int nc = p.second;
		for (int i = 0; i < (int)to[t].size(); i++) {
			if (to[t][i] == s) continue;
			++nc;
			nc %= mx;
			int nf = to[t][i];
			mp[make_pair(t, nf)] = nc;
			q.push(make_pair(make_pair(t, nf), nc));
		}
	}

	cout << mx << endl;
	rep(i,n - 1) {
		cout << mp[v[i]] + 1 << endl;
	}
}

int main() {
	solve();
	return 0;
}