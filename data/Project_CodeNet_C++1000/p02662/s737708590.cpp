#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define int long long
#define pii pair<int, int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define jai_shree_ram  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i, a, b, d) for (int i = a; i <= b; i += d)
#define brep(i, a, b, d) for (int i = a; i >= b; i -= d)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int MOD = 998244353;
////////////////////////////////

int dp[3005][3005];

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    jai_shree_ram
    int n, s;
    cin >> n >> s;
    int a[n+1];
    rep(i,1,n,1) cin >> a[i];

    dp[0][0] = binpow(2, n, MOD);

    map <int, int> inv;
    inv[1] = 1;
    int m = MOD;
    inv[2] = (m - (m/2) * inv[m%2] % m) % m;

    rep(i,1,n,1){
        rep(sum,0,s,1){
            dp[i][sum] += dp[i-1][sum];
            dp[i][sum] %= MOD;
            if(sum >= a[i]){

                dp[i][sum] += ((dp[i-1][sum-a[i]]%MOD  * inv[2]%MOD)%MOD);
                
                dp[i][sum] %= MOD;
            }
        }
    }

    cout << dp[n][s]%MOD << endl;
    return 0;    
}