//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("fma,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define x first
#define y second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int x, a;
    cin >> x >> a;
    if (x >= a) cout << 1;
    cout << 0;

    return 0;
}
