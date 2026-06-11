#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// auto mod int
const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep (i, n) cin >> a[i];
    int r = 0, b = 0, g = 0; // r>=b>=g
    ll ans = 1;
    rep (i, n) {
        if (a[i] == r && a[i] == b && a[i] == g) {
            (ans *= 3) %= mod;
            r++;
        } else if (a[i] == r && a[i] == b) {
            (ans *= 2) %= mod;
            r++;
        } else if (a[i] == r) {
            r++;
        } else if (a[i] == b & a[i] == g) {
            (ans *= 2) %= mod;
            b++;
        } else if (a[i] == b) {
            b++;
        } else if (a[i] == g) {
            g++;
        } else
            ans = 0;
    }
    cout << ans << "\n";
}
