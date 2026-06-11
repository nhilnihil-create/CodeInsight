#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, K;
ll num[100001];
map<ll, ll> powN;

ll powll(ll x){
    vector<ll> v;
    v.push_back(x);
    for(ll i = 1; (1 << i) <= N; i++){
        v.push_back(v[i - 1] * v[i - 1] % MOD);
    }
    ll ret = 1;
    for(ll i = 0; (1 << i) <= N; i++){
        if((1 << i) & N) ret = ret * v[i] % MOD;
    }
    return ret;
}

signed main(){
    cin >> N >> K;
    ll ans = 0;
    for(ll i = K; i >= 1; i--){
        num[i] = powll(K / i);
        for(ll j = 2; i * j <= K; j++) num[i] = (num[i] + MOD - num[i * j]) % MOD;
        ans = (ans + i * num[i] % MOD) % MOD;
    }
    PRINT(ans);
    return 0;
}