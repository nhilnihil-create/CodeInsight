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

const int mod = 1e9 + 7;
ll modpow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

int main() {
    int x, y;
    cin >> x >> y;
    ll ans = 1;
    if ((x + y) % 3 != 0) ans = 0;
    int n = (x + y) / 3;
    if (x < n || y < n) ans = 0;
    int nx = x - n, ny = y - n;
    rep (i, 0, nx + ny) {
        ans = ans * (i + 1) % mod;
        ll j = modpow (i + 1, mod - 2);
        // cout << j << " ";
        if (i < nx) ans = ans * j % mod;
        // cout << ans << " ";
        if (i < ny) ans = ans * j % mod;
        // cout << ans << "\n";
    }
    cout << ans << "\n";
}
