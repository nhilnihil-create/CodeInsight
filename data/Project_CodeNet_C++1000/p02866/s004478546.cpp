#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main() {
    ll N;
    cin >> N;
    vector<ll> D(N);
    vector<ll> C(N+1, 0);
    for(ll i = 0; i < N; i++){
        cin >> D.at(i);
    }
    for(ll i = 0; i < N; i++){
        C.at(D.at(i))++;
    }
    
    if(D.at(0) != 0){
        printf("0\n");
        return 0;
    }
    if(C.at(0) != 1){
        printf("0\n");
        return 0;
    }
    
    ll ans = 1;
    ll tmp;
    ll p, q;
    for(ll i = 0; i < N-1; i++){
        q = C.at(i+1);
        p = C.at(i);
        tmp = 1;
        while(q >= 1){
            if(q & 1) tmp = tmp * p % MOD2;
            p = p * p % MOD2;
            q >>= 1;
        }
        ans = ans * tmp % MOD2;
    }
    
    printf("%lld\n", (ans + MOD2) % MOD2);
    return 0;
}