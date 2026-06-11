#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    ll n;
    cin >> n;

    vector<pair<ll, int>> primes;
    ll t = n;
    for (ll i = 2; i * i <= t; i++) {
        int cnt = 0;
        while (t % i == 0) {
            cnt++;
            t /= i;
        }
        if (cnt) primes.eb(i, cnt);
    }
    if (t != 1) primes.eb(t, 1);

    int cnt = 0;
    function<void(int, ll)> solve = [&](int i, ll cur) {
        if (i != sz(primes)) {
            ll a = 1;
            rep(j, primes[i].se + 1) {
                solve(i + 1, cur * a);
                a *= primes[i].fi;
            }
        } else if (cur != 1) {
            ll n1 = n;
            while (n1 % cur == 0) n1 /= cur;
            if ((n1 - 1) % cur == 0) cnt++;
        }
    };
    solve(0, 1);

    vector<pair<ll, int>> primes2;
    ll t2 = n - 1;
    for (ll i = 2; i * i <= t2; i++) {
        int cnt = 0;
        while (t2 % i == 0) {
            cnt++;
            t2 /= i;
        }
        if (cnt) primes2.eb(i, cnt);
    }
    if (t2 != 1) primes2.eb(t2, 1);

    ll cur = 1;
    for (auto& i : primes2) {
        cur *= i.se + 1;
    }
    cnt += cur - 1;

    cout << cnt;

    return 0;
}
