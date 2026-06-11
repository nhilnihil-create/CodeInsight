#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
ll Pow(ll a, ll n) {
    if (n == 0) return 1;
    if (n % 2) return (a * Pow(a, n - 1)) % mod;
    else {
        ll k = Pow(a, n / 2);
        return (k * k) % mod;
    }
}
ll gyakusuu[2001];
ll nCk(ll n, ll k) {
    ll ret = 1;
    for (ll i = 1; i <= k; i++) {
        ret = ret * (n - k + i) % mod;
        ret = ret * gyakusuu[i] % mod;
    }
    return ret;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    for (int i = 1; i <= 2000; i++) {
        gyakusuu[i] = Pow(i, mod - 2);
    }
    for (int i = 1; i <= k; i++) {
        cout << nCk(k - 1, i - 1) * nCk(n - k + 1, i) % mod << endl; 
    }
    return 0;
}