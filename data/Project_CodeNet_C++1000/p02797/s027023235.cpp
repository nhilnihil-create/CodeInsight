#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n, k, s;
    cin >> n >> k >> s;

    if (s == 1000000000LL) {
        rep(i, k) { cout << s << " "; }
        rep(i, n - k) { cout << 1 << " "; }
    } else {
        rep(i, k) { cout << s << " "; }
        rep(i, n - k) { cout << s + 1 << " "; }
    }
    cout << endl;
    return 0;
}

