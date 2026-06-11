#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll mod = 1000000007;

int n, k;

ll dfs(int v, int p, vector<vector<int>> &G){
	int col_num;
	if(p == -1) col_num = k-1;
	else col_num = k-2;
	if(k < G[v].size()) return 0;
	ll case_num = 1;
	for(auto nv : G[v]){
		if(nv == p) continue;
		case_num *= col_num;
		col_num--;
		case_num %= mod;
	}
	for(auto nv : G[v]){
		if(nv == p) continue;
		case_num *= dfs(nv, v, G);
		case_num %= mod;
	}
	return case_num;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
	vector<vector<int>> G(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
	ll ans = k * dfs(0, -1, G);
	ans %= mod;
	cout << ans << endl;
    return 0;
}
