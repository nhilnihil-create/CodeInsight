#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

    #pragma GCC optimize("O3")
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    /*#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
    #pragma GCC target ("avx2")*/

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

ll MAX = 1e15;
double PI = 3.141592653589793238463;
//double PI = acos(-1);
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll md = 998244353;

void solve(){
    ll n,s;
    cin >> n >> s;
    vector<ll> nums(n);
    for(ll i=0; i<n; i++){
        cin >> nums[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(s+1));
    dp[0][0]=1;
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=s; j++){
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=md;
            dp[i][j]*=2;
            dp[i][j]%=md;
            ll prev = j-nums[i-1];
            if(prev>=0){
                dp[i][j]+=dp[i-1][prev];
                dp[i][j]%=md;
            }
        }
    }


    cout << dp[n][s];

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }


    return 0;
}
