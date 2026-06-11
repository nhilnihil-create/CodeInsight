#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {cin >> a[i] >> b[i]; mx = max(mx, a[i]);}
    //for(int i = 0; i < n; i++) cout << a[i] << " " << b[i] << "\n";
    int len = h + mx + 1;
    vector<vector<ll>> dp(n + 1, vector<ll>(len, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int val = a[i - 1];
        //cout << val << " ";
        for(int j = 0; j < len; j++){
            if(j < val) dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = min(dp[i - 1][j], dp[i][j - val] + b[i - 1]);
            }
        }
    }
    ll mn = LLONG_MAX;
    //for(int i = 0; i <= n; i++) {cout << "\n"; for(int j = 0; j < len; j++) cout << dp[i][j] << " ";}
    for(int i = 0; i <= n; i++){
        for(int j = h; j < len; j++){
            mn = min(mn, dp[i][j]);
        }
    }
    cout << mn;
}