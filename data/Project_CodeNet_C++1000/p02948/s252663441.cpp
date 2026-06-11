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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(100001);
	rep(i,n) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	priority_queue<pii> p;
	ll ans = 0;
	for (int i = 1; i<= m; i++) {
		for (int x: v[i]) {
			p.push(pii(x, i));
		}
		if (p.empty()) continue;
		ans += p.top().first;
		p.pop();
	}
	cout << ans << endl;
}