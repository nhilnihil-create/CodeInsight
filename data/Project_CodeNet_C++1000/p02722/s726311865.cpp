#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define lll __int128
#define lp(i, a, b) for (int i = a; i < b; i++)
#define vec(v, type, sz) vector<type> v(sz)
#define in(v) \
    for (auto &i : v) cin >> i
#define all(v) v.begin(), v.end()
#define prv(v)                         \
    for (auto i : v) cout << i << " "; \
    cout << "\n"
#define MOD 1000000007
#define INF 1000000000
#define INFL 1000000000000000000ll
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vl vector<ll>
#define vii(v, n, m, val) vector<vector<int>> v(n, vector<int>(m, val))
#define viii(v, i, j, k, val)        \
    vector<vector<vector<int>>> v(i, \
                                  vector<vector<int>>(j, vector<int>(k, val)))
#define pii pair<int, int>
#define pb push_back
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int count_factors(ll n) {
    int cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n)
                cnt++;
            else
                cnt += 2;
        }
    }
    return cnt;
}

bool ok(ll n, ll k) {
    while (n % k == 0) n /= k;
    return n % k == 1;
}

int main() {
    fast_io;
    ll n;
    cin >> n;
    ll ans = count_factors(n - 1) - 1;
    for (ll k = 2; k * k <= n; k++) {
        if (n % k == 0) {
            if (k * k == n)
                ans += ok(n, k);
            else {
                ans += ok(n, k);
                ans += ok(n, n / k);
            }
        }
    }
    ans++;  // for n/n=1;
    cout << ans;
}