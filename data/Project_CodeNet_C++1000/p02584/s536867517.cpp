//(UNCOMMENT WHEN SUBMITTING)
//#pragma GCC optimize("O3")

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
// #pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

// clang-format off
#define range(i) for (int _ = 0; _ < i; _++)
#define vprnt(v) for (auto vi : v) cout << vi << " "; cout << endl;
#define fastio() ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace ::std;
int nxt() {int x;cin >> x;return x;}
ll nxtll() {ll x;cin >> x;return x;}
// clang-format on

int main() {
    fastio();
    ll X = nxtll(), K = nxtll(), D = nxtll();

    X = abs(X);

    ll division = X / D;
    if (division >= K) {
        cout << abs(X - D * K) << endl;
    } else {
        ll modulo = (K - division) % 2LL;
        if (modulo == 0) {
            cout << abs(X - D * division) << endl;
        } else {
            cout << abs(X - D * (division + 1)) << endl;
        }
    }

    return 0;
}
