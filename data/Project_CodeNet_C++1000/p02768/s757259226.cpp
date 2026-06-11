#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const ll mod = 1000000007;

ll modpow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = modpow (2, n) - 1;
    ll aa = 1, bb = 1;
    for (ll i = 1; i <= a; i++) {
        aa = aa * (n - i + 1) % mod * modpow (i, mod - 2) % mod;
    }
    for (ll i = 1; i <= b; i++) {
        bb = bb * (n - i + 1) % mod * modpow (i, mod - 2) % mod;
    }
    ans -= aa + bb;
    while (ans < 0) ans += mod;
    cout << ans << "\n";
}
