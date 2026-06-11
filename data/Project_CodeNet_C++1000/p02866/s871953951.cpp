#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 998244353;

ll modpow(ll a, ll n)
{
    ll res = 1;
    while (n > 0) {
        if (n % 2) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> D(N); // iとの距離
    vector<ll> cnt(N); // 距離iにいくつのノードがあるか
    rep(i, N)
    {
        cin >> D[i];
        cnt[D[i]]++;
    }
    ll res = 1;
    // 距離maxdのノードがあれば,そのノードにたどり着くためにそれ以下の距離のノードもある
    bool flag = false;
    for (int maxd = N - 1; maxd >= 1; --maxd) {
        if (cnt[maxd] != 0) {
            flag = true;
        }
        if (flag && cnt[maxd] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    if (cnt[0] != 1 || D[0] != 0) { // 最初のノードだけが距離0
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < N; i++) {
        res *= modpow(cnt[i - 1], cnt[i]);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}