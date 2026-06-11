#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    ll cnt = 0;
    for (ll i = k; i <= n + 1; i++) {
        cnt += (i * (n - i + 1) + 1) % MOD;
    }
    cout << cnt % MOD << endl;
    return 0;
}