#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;


const ll MOD = 998244353;

int main() {
    int n, s; cin >> n >> s;
    vvll f(n + 1, vll (s + 1));
    vll a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    f[0][0] = 1;
    FOR(i, 1, n) {
        FOR(j, 0, s) {
            f[i][j] = 2 * f[i - 1][j];
            if (j >= a[i]) f[i][j] += f[i - 1][j - a[i]];
            f[i][j] %= MOD;
        }
    }
    cout << f[n][s] << endl;
}