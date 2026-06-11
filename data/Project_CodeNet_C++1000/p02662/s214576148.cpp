#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<vector<ll> > dp((N + 1), vector<ll> (3005));
    rep(i,N + 1){
        rep(j,3005){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (ll i = 0; i < N; i++){
        for (ll j = 0; j <= 3000; j++){
            if (j + A[i] <= 3000) dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] + dp[i][j]) % 998244353;
            dp[i + 1][j] = (dp[i + 1][j] + (dp[i][j] * 2) % 998244353) % 998244353;
        }
    }
    cout << dp[N][S] % 998244353 << endl;
}
