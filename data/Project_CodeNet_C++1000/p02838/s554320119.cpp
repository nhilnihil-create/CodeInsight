#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

ll pw[60], cum[N][65];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pw[0] = 1;
    for(int i = 1; i <= 61; i++) pw[i] = pw[i - 1] * 2 % mod;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        for(int j = 0; j < 61; j++){
            cum[i][j] = (x >> j & 1);
            cum[i][j] += cum[i - 1][j];
        }
    }
    ll ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 61; j++){
            int kam = cum[n][j] - cum[i][j];
            if(cum[i][j] - cum[i - 1][j] == 1) kam = n - i - kam;
            ll tmp = pw[j] * kam % mod;
            ans = (ans + tmp) % mod;
        }
    }
    cout << ans;


    return 0;
}
