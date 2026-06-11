#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const long long MOD = 1000000007;

int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> a(N+5,0);
    for(int i=0;i<M;i++){
        ll b;
        cin >> b;
        a[b] =1;
    }
    
    ll dp[N+5] = {};
    dp[0] = 1;
    for(int i=0;i<N;i++){
        dp[i] %= MOD;
        if(a[i+1] ==0){
            dp[i+1] += dp[i];
        }
        if(a[i+2] == 0){
            dp[i+2] += dp[i];
        }
    }
    cout << dp[N] % MOD << endl;


    return 0;
}