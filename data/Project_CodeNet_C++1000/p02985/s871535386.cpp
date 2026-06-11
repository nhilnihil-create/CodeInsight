#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

const int mod = 1e9+7;

ll P(ll l, ll r){
	ll ret = 1;
	for(ll i = 0; i < r; i++){
		ret *= (l-i);
		ret %= mod;
	}
	return ret;
}

ll dfs(vector<vector<int>> &tree, int now, int bf, int k){
	ll ret = 1;
	if(bf == -1){
		ret = k * P(k-1, tree.at(now).size());
		ret %= mod;
	}else{
		ret = P(k-2, tree.at(now).size()-1);
	}
	for(int i : tree.at(now)){
		if(bf == i) continue;
		ret *= dfs(tree, i, now, k);
		ret %= mod;
	}
	return ret;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> tree(n, vector<int>());
	rep(i, n-1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree.at(a).push_back(b);
		tree.at(b).push_back(a);
	}
	ll ans = dfs(tree, 0, -1, k);
	cout << ans << endl;
	return 0;
}