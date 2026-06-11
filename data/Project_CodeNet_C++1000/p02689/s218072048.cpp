#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<int> h(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> h[i];

	vector<vector<int>> g(n + 1);
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;

	for(int u = 1; u <= n; u++){
		int mx = -1;
		for(auto &v : g[u])
			mx = max(mx, h[v]);

		if(h[u] > mx)
			++ans;
	}

	cout << ans << endl;

	return 0;
}
