#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include<stack>
#include<string>
#include<algorithm> 
#include <set>
#include<list>
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
typedef long long int ll;
using namespace std;
const int MOD = 1000000007;


ll modPow(ll a, ll n, ll p) {
    if (n == 0) return 1; 
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}

ll ModuleFrac(ll N,ll K, ll M) {
    ll modu = 1;
    for (int i = 0; i <K; i++) {
        modu = (modu * (N-i)) % M;
    }
    return modu;
}
int main() {
    ll N, a, b; cin >> N >> a >> b;
    ll ans;
    ans = (modPow(2, N, MOD)) % MOD;
    ans -= ((ModuleFrac(N, a, MOD)) * (modPow(ModuleFrac(a, a, MOD), MOD - 2, MOD))) % MOD;
    ans -= ((ModuleFrac(N, b, MOD)) * (modPow(ModuleFrac(b, b, MOD), MOD - 2, MOD))) % MOD;
    ans--;
    while (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
}