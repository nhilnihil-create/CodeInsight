#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 1e5 + 5;
ll dp[N];
ll mod = 1e9 + 7;
vector<ll> node[N];
ll ans = 1, k;
void dfs(ll u, ll p){
        ans *= max(0ll, k - dp[p]);
        ans %= mod;
        if (p != 0) dp[u] = 2;
        else dp[u] = 1;
        for (auto j : node[u]){
                if (j != p) {
                        dfs(j, u);
                        dp[u]++;
                }
        }
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(".INP", "r")){
                freopen(".INP", "r", stdin);
                freopen(".OUT", "w", stdout);
        }
        ll n;
        cin >> n >> k;
        for (int i = 1; i < n; i++){
                ll u, v;
                cin >> u >> v;
                node[u].push_back(v);
                node[v].push_back(u);
        }
        dfs(1, 0);
        cout << ans;
}
