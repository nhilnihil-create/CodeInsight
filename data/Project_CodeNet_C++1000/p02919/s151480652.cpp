#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

//#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define mkt make_tuple
#define no {cout << "No"; return;}

const int N = 1e5 + 7;

int p[N], t[4 * N];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = p[l];
        return;
    }
    int m = l + r >> 1;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m + 1, r);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}

int ask(int v, int l, int r, int L, int R, int x, bool flag, int n) {
    if (l > R || r < L || t[v] < x)
        return (!flag ? n : -1);
    if (l == r)
        return l;
    int m = l + r >> 1;
    int pans = (!flag ? ask(2 * v + 1, l, m, L, R, x, flag, n) : ask(2 * v + 2, m + 1, r, L, R, x, flag, n));
    return (pans != -1 && pans != n ? pans : (!flag ? ask(2 * v + 2, m + 1, r, L, R, x, flag, n) : ask(2 * v + 1, l, m, L, R, x, flag, n)));
}

void solve() {
    int n; cin >> n;
    vector <int> nxt(n, n), prv(n, -1), snxt(n), sprv(n);
    stack <int> s;
    loop(i, n) {
        cin >> p[i];
        while (!s.empty() && p[s.top()] < p[i]) {
            nxt[s.top()] = i; s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && p[s.top()] < p[i]) {
            prv[s.top()] = i; s.pop();
        }
        s.push(i);
    }
    build(0, 0, n - 1);
    loop(i, n) {
        sprv[i] = ask(0, 0, n - 1, 0, prv[i] - 1, p[i], 1, n);
        snxt[i] = ask(0, 0, n - 1, nxt[i] + 1, n - 1, p[i], 0, n);
    }
    ll ans = 0;
    loop(i, n) {
        if (prv[i] != -1)
            ans += ll(prv[i] - sprv[i]) * (nxt[i] - i) * p[i];
        if (nxt[i] != n)
            ans += ll(snxt[i] - nxt[i]) * (i - prv[i]) * p[i];
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}