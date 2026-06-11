#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

int main() {
    ll n, k;
    cin(n); cin(k);

    vector<ll> a(n), f(n);
    rep2(i, n) cin(a[i]);
    rep2(i, n) cin(f[i]);

    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());

    ll left = -1, right = 1e12;
    while(left + 1 < right) {
        ll middle = (left + right) / 2;

        bool ok = [&]{
            ll sum = 0;
            rep2(i, n) {
                sum += max(0ll, a[i] - middle / f[i]);
            }
            return sum <= k;
        }();

        if (ok) right = middle;
        else left = middle;
    }

    print(right);
    return 0;
}