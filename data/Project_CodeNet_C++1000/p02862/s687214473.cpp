#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int x, y;
ll modPow(ll n, int m) {
    if (m == 0) return 1;
    ll ret = modPow(n, m/2);
    ret = ret * ret % MOD;
    if (m % 2) ret = n * ret % MOD;
    return ret; 
}
ll comb(int n, int k){
    if (n - k < k) k = n - k;
    ll ret = 1;
    for (ll i = 1; i <= k; i++) {
        ret = ret * (n - i + 1) % MOD;
        ret = ret * modPow(i, MOD - 2) % MOD;
    }
    return ret;
}
int main() {
    cin >> x >> y;
    bool cannot = true;
    int elbow_x, elbow_y;
    for (int i = 0; i <= x; i += 2) {
        int j = i / 2;
        if ((x - i) * 2 == y - j) {
            cannot = false;
            elbow_x = i / 2, elbow_y = (y - j) / 2;
        }
    }
    if (cannot) {
        cout << 0 << endl;
        return 0;
    }
    cout << comb(elbow_x + elbow_y, elbow_x) << endl;
    return 0;
}