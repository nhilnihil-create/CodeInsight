#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;


int main(void){
    ll N;
    cin >> N;
    
    vector<ll> cnt(N + 1, 0);
    cnt.at(0) = 3;
    ll tmp;
    ll ans = 1;
    for(ll i = 0; i < N; i++){
        cin >> tmp;
        ans = ans * (cnt.at(tmp) - cnt.at(tmp + 1)) % MOD;
        cnt.at(tmp + 1)++;
    }
    
    printf("%lld\n", ans);
}
