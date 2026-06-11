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
    ll n;
    cin(n);

    vector<ll> a(n + 1), b(n);
    rep2(i, n + 1) cin(a[i]);
    rep2(i, n) cin(b[i]);

    ll ans = 0;
    rep3(i, 1, n + 1) {
        ll ta = a[i - 1] + a[i];
        ll tb = b[i - 1];

        if (ta > tb) {
            ans += tb;

            if (a[i - 1] < b[i - 1]) {
                ll temp = a[i] - tb + a[i - 1];
                if (temp > 0) a[i] = temp;
                else a[i] = 0;
            }
        } else {
            ans += ta;
            a[i] = 0;
        }
    }

    print(ans);
    return 0;
}