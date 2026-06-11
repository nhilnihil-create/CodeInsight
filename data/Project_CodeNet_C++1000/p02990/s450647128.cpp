#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define rep(i, n) for(int i=0; i<n; ++i)
#define REP(i, n) for(int i=1; i<=n; ++i)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
const int inf = 1e9;
const ll INF = 1e18;
const ll MOD = 1e9+7;
const ll MAX = 1e9+7;

ll fact[10003];
 
template<typename T> void factorial(T m){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i <= 10000; ++i){
        fact[i] = fact[i-1] * i % m;
    }
}
template<typename T> T Pow(T x, T n, T m){
    if(n == 0) return 1;
    if(n % 2 == 0) return Pow(x * x % m, n / 2, m);
    else return x * Pow(x, n - 1, m) % m;
}
template<typename T> T combination(T n, T k, T m){
    return fact[n] * Pow<T>(fact[k], m-2, m) % m * Pow<T>(fact[n-k], m-2, m) % m;
}

int main(){
    ll n, k; cin >> n >> k;
    factorial<ll>(MOD);
    REP(i, k){
        if(n-k+1 >= i){
            cout << combination<ll>(n-k+1, i, MOD) * combination<ll>(k-1, i-1, MOD) % MOD << endl;
        }else cout << 0 << endl;
    }
    return 0;
}