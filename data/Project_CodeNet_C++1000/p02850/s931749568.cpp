#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int INF = 1e9+7;
const int mod= 1e9 + 7;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<vector<int>> G(N);
	vector<pair<int, int>> vp;
	for (int i = 1; i < N; i ++ ) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		vp.emplace_back(a, b);
	}
	int K = 0;
	map<pair<int, int>, int> mp;

	vector<int> cs(N, 0);
	vector<bool> used(N, false);

	queue<int> que;

	used[0] = 1;
	que.emplace(0);


	while (!que.empty()) {
		int v = que.front(); que.pop();
		K = max(K, int(G[v].size()));
		int cur = 1;

		for (int u : G[v]) {
			if (used[u])continue;
			if (cs[v] == cur)cur++;
			cs[u] = mp[make_pair(u, v)] = mp[make_pair(v, u)] = cur++;
			used[u] = true;
			que.emplace(u);
		}
	}


	cout << K << endl;
	for (auto p : vp)cout << mp[p] << endl;




	return 0;
}
