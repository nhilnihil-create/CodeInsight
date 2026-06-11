#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vi c(n + 1);
    vvi ps(n + 1, vi(4));
    FOR(i, 0, n - 1) {
        if (s[i] == 'R') c[i + 1] = 1;
        else if (s[i] == 'G') c[i + 1] = 2;
        else c[i + 1] = 3;
        ps[i + 1][c[i + 1]]++;
        FOR(j, 1, 3)
            ps[i + 1][j] += ps[i][j];
    }
    vvi ss(n + 2, vi(4));
    ROF(i, n, 1) {
        ss[i][c[i]]++;
        FOR(j, 1, 3)
            ss[i][j] += ss[i + 1][j];
    }
    ll ans = 0;
    FOR(i, 1, n) {
        FOR(j, 1, 3) FOR(k, 1, 3) {
            if (c[i] ^ j ^ k ^ 1 ^ 2 ^ 3) continue;
            ans += ps[i - 1][j] * ss[i + 1][k];
        }
        for (int j = 1; i - j > 0 && i + j <= n; j++)
            if ((c[i] ^ c[i - j] ^ c[i + j] ^ 1 ^ 2 ^ 3) == 0)
                ans--;
    }
    cout << ans << endl;
}