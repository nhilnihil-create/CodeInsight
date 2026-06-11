#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

vector<int> toposo(vector<vector<int>>& g) {
	vector<int> h(g.size());
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			h[g[i][j]]++;
		}
	}
	//入次数が0の頂点の集合
	stack<int> st;

	//入次数が0の頂点であればstに追加
	for(int i = 0; i < g.size(); i++) if (h[i] == 0) st.push(i);

	//ソートされた後のグラフ
	vector<int> ans;
	//stがなくなるまでループ
	while (st.size()) {
		//stの集合のから一つ取り出す
		int i = st.top(); st.pop();
		ans.push_back(i);
		for (auto& j : g[i]) {
			//隣接する頂点の入次数をマイナス1
			h[j]--;
			//これによって入次数が0になればstに追加
			if (h[j] == 0) st.push(j);
		}
	}
	return ans;
}

int main() {
	io_init;
	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N - 1));
	for (int i = 0; i < N; i++) for (int j = 0; j < N - 1; j++) {
		cin >> A[i][j];
		A[i][j]--;
	}
	vector<vector<int>> g(N * (N - 1) / 2);
	vector<vector<int>> par(N * (N - 1) / 2);
	vector<vector<int>> conv(N, vector<int>(N, -1));
	for (int i = 0, n = 0; i < N - 1; i++)for (int j = i + 1; j < N; j++, n++) {
		conv[i][j] = n;
		conv[j][i] = n;
	}
	for (int i = 0; i < N; i++)for (int j = 0; j < N - 2; j++) {
		g[conv[i][A[i][j]]].push_back(conv[i][A[i][j + 1]]);
		par[conv[i][A[i][j + 1]]].push_back(conv[i][A[i][j]]);
	}
	for (int i = 0; i < g.size(); i++) {
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
		sort(par[i].begin(), par[i].end());
		par[i].erase(unique(par[i].begin(), par[i].end()), par[i].end());
	}
	auto tp = toposo(g);

	if (tp.size() != g.size()) {
		cout << -1 << endl;
		return 0;
	}

	vector<ll> dp(N * (N - 1) / 2, 0);
	for (int i = 0; i < tp.size(); i++) {
		ll mx = -1;
		for (int j = 0; j < par[tp[i]].size(); j++) {
			mx = max(mx, dp[par[tp[i]][j]]);
		}
		dp[tp[i]] = mx + 1;
	}
	cout << *max_element(dp.begin(), dp.end()) + 1 << endl;
}