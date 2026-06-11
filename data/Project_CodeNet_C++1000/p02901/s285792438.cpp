#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n,m; cin >> n >> m;
    ll a[m],c[m];
    rep(i,m){
        int b;
        cin >> a[i] >> b;
        int S = 0;
        rep(j,b){
            int bit; cin >> bit;
            bit--;
            S = S | (1<<bit);
        }
        c[i] = S;
    }
    ll dp[m+1][1<<n];
    rep(i,m+1) rep(j,(1<<n)) dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i = 0; i < m; i++){
        for(int S = 0; S < (1<<n); S++){
            dp[i+1][S] = min(dp[i+1][S],dp[i][S]);
            int T = (S | c[i]);
            dp[i+1][T] =  min(dp[i+1][T], dp[i][S] + a[i]);
        }
    }
    if(dp[m][(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[m][(1<<n)-1] << endl;
}