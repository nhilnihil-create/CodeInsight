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
    ll K = nxtll();

    set<ll> visit;
    ll last = -1;
    ll curr = 7;
    int count = 0;
    if (K % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    while (visit.find(last) == visit.end() && last != 0) {
        // cout << curr << " : " << last << endl;
        visit.emplace(last);
        last = curr % K;
        curr = 10LL * last + 7LL;
        count++;
    }

    if (last == 0) {
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
