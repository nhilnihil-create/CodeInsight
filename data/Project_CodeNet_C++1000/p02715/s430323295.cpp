#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = ll(1000000000+7);

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

int main(void)
{
    ll N, K;
    cin >> N >> K;
    vector<ll> ans(K+1, 0ll);
    for(int k=K;k>=1;k--){
        ll d = K / k;
        ll a = mpow(d, N);
        for(int m=2;m<=d;m++){
            a += MOD - ans[m*k]; a %= MOD;
        }
        ans[k] = a;
    }
    ll answer = 0ll;
    for(int k=1;k<=K;k++){
        answer += ans[k] * k; answer %= MOD;
    }
    cout << answer << endl;

    return 0;
}