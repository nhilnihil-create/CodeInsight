//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


inline void print(){
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest){
    cout << first << ' ';
    print(rest...);
}


const long long MOD = 1000000007;


long long mod_pow(long long x, long long n, long long mod) {
    if (n == 0) return 1;
    long long res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res; 
}


long long com(long long n, long long k) {
    long long mul = 1;
    long long div = 1;
    for (long long i = 0; i < k; i++) {
        mul = (mul * (n - i)) % MOD;
        div = (div * (i + 1)) % MOD;
    }
    div = mod_pow(div, MOD-2, MOD);
    return (mul * div) % MOD;
}


void solve() {
    long long n, a, b; cin >> n >> a >> b;
    long long ans = mod_pow(2, n, MOD) - 1;
    ans -= com(n, a);
    ans = (ans<0 ? ans+MOD : ans);
    ans -= com(n, b);
    ans = (ans<0 ? ans+MOD : ans);
    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}