#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
const ll MOD = 998244353;
 
ll mpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
ll minv(ll a) {
    return mpow(a, MOD - 2);
}

int n, s;
ll val[3005];
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll speed = minv(2);

    cin >> n >> s;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
        
        for (int j = s - i; j >= 0; --j) {
            val[j + i] += val[j] * speed % MOD;
            val[j + i] %= MOD;
        }

        val[i] += mpow(2, n - 1);
        val[i] %= MOD;
    }
    cout << val[s] % MOD;
}
