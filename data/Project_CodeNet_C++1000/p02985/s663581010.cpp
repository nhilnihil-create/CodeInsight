#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll mod = 1000000007;
const int limit = 100005;
int n, k;
ll cnt[limit];

void dfs(int v, int p, int kind, vector<vector<int>> &G){
	cnt[v] = max(kind,0);
	int c = 1;
	if(p != -1) c++;
	for(auto nv : G[v]){
		if(nv == p) continue;
		dfs(nv, v, k - c, G);
		c++;
	}
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
	memset(cnt, 0, sizeof(cnt));
    dfs(0, -1, k, G);
	ll ans = 1;
	rep(i,n){
		ans = (ans * cnt[i]) % mod;
	}
	cout << ans << endl;
    return 0;
}
