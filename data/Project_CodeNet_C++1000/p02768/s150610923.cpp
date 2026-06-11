#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll MOD = 1000000007;
const int MAX = 200001;
ll inv[MAX];
ll FactorialInv[MAX];
ll Factorial[MAX];

ll powmod(ll a, ll b){
    a %= MOD;
    if(b == 0){
        return 1;
    }
    ll ans = powmod(a, b / 2);
    ans = ans * ans % MOD;
    if(b % 2 == 1){
        ans = ans * a % MOD;
    }
    return ans;
}
void init_combination(){
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % MOD;
    }
    FactorialInv[MAX] = powmod(Factorial[MAX], MOD - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % MOD;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % MOD;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ret = 1;
    for(ll i = 0; i < b; i++) {
        ret *= (a - i);
        ret %= MOD;
        ret *= powmod(i + 1, MOD - 2);
        ret %= MOD;
    }
    return ret;
}

int main() {
    init_combination();
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = powmod(2, n) - 1;
    ans -= combination(n, a);
    ans -= combination(n, b);
    ans += 2 * MOD;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
