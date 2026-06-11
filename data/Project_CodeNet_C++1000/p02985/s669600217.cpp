#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> g[N];
int k;

int mul(int a, int b){
	return (1ll * a * b) % mod;
}
int dfs(int node, int parent){
	int rem = k - 1;
	if(parent != -1)
		rem--;
	int ans = 1;
	for(auto &child : g[node]){
		if(child == parent)
			continue;
		ans = mul(ans, rem--);
		ans = mul(ans, dfs(child, node));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	int n;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout << mul(k, dfs(1, -1));
	return 0;
}
