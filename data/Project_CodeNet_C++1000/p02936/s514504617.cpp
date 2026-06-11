#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Tree {
	int N;
	vector<vector<int>> edge;
	vector<int> lazy;

public:
	Tree(int N) : N(N), edge(N), lazy(N) {}
	void input() {
		REP(i, N - 1) {
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			edge[a].emplace_back(b);
			edge[b].emplace_back(a);
		}
	}
	void add(int p, int x) {
		lazy[p] += x;
	}
	void dfs(int i = 0, int p = -1) {
		if (p >= 0) lazy[i] += lazy[p];
		for (auto &j : edge[i]) {
			if (j != p) {
				dfs(j, i);
			}
		}
	}
	void ans() {
		dfs();
		REP(i, N) {
			cout << lazy[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	Tree tree(N);
	tree.input();
	REP(q, Q) {
		int p, x;
		cin >> p >> x;
		--p;
		tree.add(p, x);
	}
	tree.ans();

	return 0;
}