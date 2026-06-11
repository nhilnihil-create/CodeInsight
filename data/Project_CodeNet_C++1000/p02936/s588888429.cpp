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

vector<vector<int>> to;

int main() {
	int n, q;
	cin >> n >> q;
	to.resize(n);
	vector<ll> p(n, 0);
	rep(i,n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	rep(i,q) {
		int x, y;
		cin >> x >> y;
		x--;
		p[x] += y;
	}
 	queue<pii> que;
	auto push = [&](int prev, int a, int b) {
		if (prev == b) return;
		p[b] += p[a];
		que.push(pii(a, b));
	};
	que.push(pii(-1, 0));
	while (!que.empty()) {
		auto pr = que.front(); que.pop();
		int prev = pr.first;
		int cur = pr.second;
		for (int i = 0; i < to[cur].size(); i++) {
			push(prev, cur, to[cur][i]);
		}
	}

	rep(i,n) {
		if (i != 0) cout << " ";
		cout << p[i];
	}
	cout << endl;
}