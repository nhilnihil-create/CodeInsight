/* Be strong, be fearless, be beautiful :D
And believe that anything is possible :))
when you have the right people there
to support you :) */
//RTn_E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define __Sync ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
#define __file freopen("input.txt", "r", stdin) ; freopen("output.txt", "w", stdout) ;
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define mk make_pair
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using mordered_set =  tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9 + 7;
const int maxn = 1e4 + 100;
const ll inf = 1e12;

//Main CODE :/\

int w[110] , v[110] , dp[110][maxn];
int main() {
    __Sync;
    int n , W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    dp[1][w[1]] = v[1];
    //cout << "i : " << 1 << " j : " << w[1] << " dp : " << dp[1][w[1]] << "\n";
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= W; j++){
            if (j < w[i]){
                dp[i][j] = dp[i - 1][j];
                //cout << "i : " << i << " j : " << j << " dp : " << dp[i][j] << "\n";
                continue;
            }
            dp[i][j] = max(dp[i - 1][j - w[i]] + v[i] , dp[i - 1][j]);
            //cout << "i : " << i << " j : " << j << " dp : " << dp[i][j] << "\n";
        }
    }
    int ans = -1;
    for (int i = W; i >= 1; i--)
        ans = max(ans , dp[n][i]);
    cout << ans << "\n";
    return 0;
}
//The_End
//Game Over :D

