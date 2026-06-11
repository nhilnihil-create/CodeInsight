#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 2e3 + 5;
const int mod = 1e9 + 7;
int n , k;
int fact[N] , inv[N];
int fp(int x , int y) {
    if(!y)
        return 1;
    int res = fp(x , y / 2);
    res = (1ll * res * res) % mod;
    if(y & 1)
        res = (1ll * res * x) % mod;
    return res;
}
void pre() {
    fact[0] = inv[0] = 1;
    for(int i = 1;i < N;i++) {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
        inv[i] = fp(fact[i] , mod - 2);
    }
}
int ncr(int n , int r) {
    if(r > n)
        return 0;
    return (1ll * (1ll * fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}
int main() {
    abdelrahman010
    pre();
    cin >> n >> k;
    for(int i = 1;i <= k;i++)
        cout << (1ll * ncr(n - k + 1, i) * ncr(k - 1 , i - 1)) % mod << '\n';
    return 0;
}