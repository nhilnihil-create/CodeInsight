#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<ll> c(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        ll s = 0;
        rep(j, b[i]){
            int d;
            cin >> d;
            d--;
            s += (1 << d);
        }
        c[i] = s;
    }
    int INF = 1001001001;
    vector<vector<int>> dp(m+1, vector<int>((1 << n), INF));
    dp[0][0] = 0;
    rep(i, m){
        rep(j, (1 << n)){
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            ll t = 0;
            rep(k, n){
                if((1 & (j >> k)) || (1 & (c[i] >> k)))t += (1 << k);
            }
            dp[i+1][t] = min(dp[i+1][t], dp[i][j] + a[i]);
        }
    }
    if(dp[m][((ll)1<<n)-1] == INF)cout << -1 << endl;
    else cout << dp[m][((ll)1<<n)-1] << endl;
}