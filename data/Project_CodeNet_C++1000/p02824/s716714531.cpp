//#pragma  GCC optimize("Ofast")

//#ifdef  DEBUG
//#define _GLIBCXX_DEBUG
//#endif

// -Ofast
// -O3
// -O2
// -fsanitize=address
// -fsanitize=undefined

// add_compile_options()

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <random>
using namespace std;
//using namesparsace __gnu_pbds;

mt19937 rnd;

void solve();

int main()
{
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    solve();
    return 0;
}

#define int long long

int max(int a, int b) {
    return a > b ? a : b;
}

const int maxN = 1e5 + 10, inf = 1e18;

bool cmp(int a, int b) {
    return a > b;
}

int n, m, v, p, a[maxN], ans, pref[maxN];

int f(int l, int r, int e) {
    int len = r - l + 1;
    return len * e - (pref[r + 1] - pref[l]);
}

void solve() {
    cin >> n >> m >> v >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    ans = p;
    for (int i = n - 1; i >= p; i--) {
        int cur = a[i] + m;
        if (cur < a[p - 1]) continue;
        int e = v - (p - 1) - (n - i);
        if (e <= 0) {
            ans = i + 1;
            break;
        } else {
            if (f(p - 1, i - 1, cur) >= e * m) {
                ans = i + 1;
                break;
            }
        }
    }
    cout << ans;
}