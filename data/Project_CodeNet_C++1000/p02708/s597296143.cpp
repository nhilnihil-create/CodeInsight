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

const int MOD = 1e9 + 7;

int main() { 
    int n, k; cin >> n >> k;
    ll ans = 0;
    vll cnt(n + 1);
    FOR(i, 1, n + 1)
        cnt[i] = (cnt[i - 1] + i) % MOD;
    FOR(i, k, n + 1) {
        // cout << cnt[n + 1] << ' ' << cnt[n - i + 1] << ' ' << cnt[i] << endl;
        ans = (ans + (cnt[n + 1] - cnt[n - i + 1]) - cnt[i] + 1 + MOD) % MOD;
    }
    cout << ans << endl;
}