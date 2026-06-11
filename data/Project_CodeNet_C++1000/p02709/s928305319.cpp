#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2050;
const int K = 1e18;
const int M = 1e9;
const int mod = 1e9 + 7;
int n;
pair <int, int> a[N];
int dp[N][N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            int x = a[i].F;
            int p = a[i].S;
            int l = j;
            int r = n - (i - j) + 1;
            if (l != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + x * abs(p - l));
            if (r != n + 1) dp[i][j] = max(dp[i][j], dp[i - 1][j] + x * abs(r - p));
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}
