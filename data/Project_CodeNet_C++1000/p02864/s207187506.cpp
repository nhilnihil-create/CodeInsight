#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 333;
const int K = 19;
const int mod = 1e9 + 7;
int um[N][N][N], bm[N][N][N], dp[N][N][N], h[N], rev[N];
map < int, int > mp;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    set < int > s;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
        s.insert(h[i]);
    }
    s.insert(0);
    int cnt = 0;
    for (auto i: s){
        mp[i] = cnt;
        rev[cnt] = i;
        cnt++;
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= cnt; j++){
            for (int l = 0; l <= k; l++){
                dp[i][j][l] = 1e18;
                um[i][j][l] = 1e18;
                bm[i][j][l] = 1e18;
            }
        }
    }
    dp[0][0][0] = 0;
    um[0][0][0] = 0;
    for (int j = 0; j < cnt; j++){
        bm[0][j][0] = 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < cnt; j++){
            for (int l = 0; l <= k; l++){
                dp[i][j][l] = 1e18;
                int nl;
                if (rev[j] != h[i]) nl = l - 1; else nl = l;
                if (nl >= 0) dp[i][j][l] = min(rev[j] + bm[i - 1][j][nl], um[i - 1][j][nl]);
                if (j != 0)
                bm[i][j][l] = min(bm[i][j - 1][l], dp[i][j][l] - rev[j]); else
                bm[i][j][l] = dp[i][j][l] - rev[j];
             //   cout << i << " " << j << " " << l << " " << dp[i][j][l] << " " << rev[j] << " " << nl << " " << bm[i - 1][j][nl] << endl;
            }
        }
        for (int j = cnt - 1; j >= 0; j--){
            for (int l = 0; l <= k; l++){
                um[i][j][l] = min(um[i][j + 1][l], dp[i][j][l]);
            }
        }
    }
    int ans = 1e18;
    for (int i = 0; i < cnt; i++){
        for (int l = 0; l <= k; l++){
            ans = min(ans, dp[n][i][l]);
        }
    }
    cout << ans;
}
