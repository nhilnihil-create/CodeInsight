#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll dfs(int K, const vector<vector<int>> &edge, int now, int from) {
	ll can_use_color_n;
	// 最初(now分使えない)
	if(from == -1) {
		can_use_color_n = K - 1;
	} else {
		// fromとnow分使えない
		can_use_color_n = K - 2;
	}

	// 自分自身以外の隣接する点の数が, 自分自身以外の濡れる個数より大きいとき色を塗ることができない
	if(K - 1 < edge[now].size()) {
		return 0;
	}

	ll case_n = 1;
	// 隣接点に色を分配
	for(auto &next : edge[now]) {
		if(next == from) continue;

		case_n *= can_use_color_n;
		case_n %= MOD;
		can_use_color_n--;
	}

	for(auto &next : edge[now]) {
		if(next == from) continue;
		case_n *= dfs(K, edge, next, now);
		case_n %= MOD;
	}
	return case_n;

}

int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> edge(N);
	for(int i=0;i<N-1;i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	ll ans = K*dfs(K, edge, 0, -1);
	ans %= MOD;
	cout << ans << endl;
}