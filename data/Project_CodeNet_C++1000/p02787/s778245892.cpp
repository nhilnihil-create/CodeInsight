#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    ll H, N;
    vll As(1010);
    vll Bs(1010);
    
    ll i, j;
    vll dp;

    cin >> H >> N;
    rep (i, N) {
        cin >> As[i] >> Bs[i];
    }

    dp.assign(H + 1, 1001001001);
    dp[0] = 0;
    rep (i, H) {
        rep (j, N) {
            dp[min(H, i + As[j])] = min(dp[min(H, i + As[j])], dp[i] + Bs[j]);
        }
    }

    cout << dp[H];

    return 0;
}