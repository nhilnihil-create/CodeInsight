#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
 
#include<deque>
#define pi 3.141592653589793238
#include<chrono>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 2e5 + 1;
ll dp[N];
vector<ll> adj[N];
void dfs(ll a, ll par){
    for(auto u : adj[a]){
        if(u == par){
            continue;
        }
        dp[u] += dp[a];
        dfs(u, a);
    }
} 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll n, q;
        cin >> n >> q;
        for(i = 0; i < n - 1; i++){
            ll a ,b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        while(q--){
            ll a, b;
            cin >> a >> b;
            dp[a] += b;
        }
        dfs(1, -1);
        for(i = 1; i <= n; i++){
            cout << dp[i] << " ";
        }
    }
    return 0;
}