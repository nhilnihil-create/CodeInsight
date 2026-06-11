#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N, Q; cin >> N >> Q;
	Graph G(N);
	for(int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<vector<int>> score(N);
	for(int i = 0; i < Q; i++) {
		int p, x; cin >> p >> x;
		p--;
		score[p].push_back(x);
	}
	stack<int> s;
	s.push(0);
	vector<int> visit(N);
	vector<ll> ans(N);
	while(!s.empty()) {
		int u = s.top();
		if(visit[u] != 1) {
			visit[u] = 1;
			for(auto v: score[u]) ans[u] += v;
			for(auto v: G[u]) {
				if(visit[v] != 1) {
					s.push(v);
					ans[v] = ans[u];
				}
			}
		}
		else s.pop();
	}
	for(int i = 0; i < N; i++) {
		if(i == N - 1) {
			cout << ans[N - 1] << endl;
			return 0;
		}
		cout << ans[i] << " ";
	}
}