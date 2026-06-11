#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
//const static ll MOD = 1e9+7;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

const static ll mod = 998244353;
int main(){
    ll N; cin >> N;
    ll Max = 0;
    vector<ll> V(N+10);
    for(int i = 0; i < N; i++){
        ll x; cin >> x; V[x]++;
        if((i == 0 && x != 0) || (i != 0 && x == 0)) {
            cout << 0 << endl; return 0;
        }
        Max = max(Max, x);
    }
    ll ans = 1;
    for(int i = 1; i < N; i++){
        ans *= modpow(V[i-1], V[i], mod);
        ans%=mod;
    }
    cout << ans << endl;

}