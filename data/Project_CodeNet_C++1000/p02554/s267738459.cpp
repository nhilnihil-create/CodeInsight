#include "bits/stdc++.h"
#include "iostream"

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lin "\n"
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(0)
#define mod 1000000007
#define PI 2 * acos(0.0)

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll x = 1;
    for (int i = 1; i <= n; ++i) {
        x = 10 * x % mod;
    }
    ans += (x % mod);
    x = 1;
    for (int i = 1; i <= n; ++i) {
        x = 9 * x % mod;
    }
    ans = ans - (x % mod);
    if (ans < 0) {
        ans += mod;
    }
    ans = ans - (x % mod);
    if (ans < 0) {
        ans += mod;
    }
    x = 1;
    for (int i = 1; i <= n; ++i) {
        x = 8 * x % mod;
    }
    ans += (x % mod);
    cout << ans % mod << lin;
}

int main() {
    fast_io;
    int t = 1;
//    cin >> t;
//    scanf("%d", &t);
    int c = 1;
    while (t--) {
//        printf("Case %lld:\n", c);
//        cout << "Case " << c << ":\n";
        solve();
        c++;
    }
}