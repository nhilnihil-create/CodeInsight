#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll mod = 1000000007;
int N, K;
ll dp[101010];

ll modpow(ll a, ll n){
    ll r = 1; a %= mod;
    while(n) r = r * ((n % 2) ? a : 1) % mod, a = a * a % mod, n >>= 1;
    return r;
}

void solve(){
    cin >> N >> K;
    ll sum = 0;
    for (int i = K; i >= 1; i--)
    {
        dp[i] = modpow(K/i, N);
        for(int j = i * 2; j <= K; j += i) dp[i] -= dp[j];
        dp[i] = (dp[i] % mod + mod) % mod;
        sum += i * dp[i] % mod;
    }
    cout << sum % mod << endl;
}
int main() {
    solve();
    return 0;
}