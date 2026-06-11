#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 1e3 + 5;
ll a[N], dp[1 << 12];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(".INP", "r")){
                freopen(".INP", "r", stdin);
                freopen(".OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        ll m;
        cin >> m;
        dp[0] = 0;
        for (int i = 0; i < (1ll << n); i++) dp[i] = 1e18;
        for (int i = 1; i <= m; i++){
                ll k;
                cin >> a[i] >> k;
                ll sum = 0;
                for (int j = 0; j < k; j++){
                        ll x;
                        cin >> x;
                        sum |= (1ll << (x - 1));
                }
                for (int j = 1; j < (1ll << n); j++){
                        if ((sum & j) == j) {
                                dp[j] = min(dp[j], a[i]);
                        }
                }
        }
        for (int i = 1; i < (1ll << n); i++){
                for (int j = 1; j <= i; j++){
                        if ((i & j) == j){
                                ll x = i;
                                x ^= j;
                                dp[i] = min(dp[i], dp[j] + dp[x]);
                        }
                }
        }
        if (dp[(1ll << n) - 1] != 1e18) cout << dp[(1ll << n) - 1];
        else cout << -1;
}
