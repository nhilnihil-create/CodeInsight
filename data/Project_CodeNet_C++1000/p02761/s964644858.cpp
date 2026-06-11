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
#include <climits>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
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
#define no {cout << -1; return;}
#define yes {cout << "Yes"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pi> v(m);
    loop(i, m)
        cin >> v[i].F >> v[i].S;
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    loop1(i, (int)v.size() - 1)
        if (v[i].F == v[i - 1].F)
            no;
    if (!v.empty() && v[0] == mkp(1ll, 0ll) && n > 1)
        no;
    vector <int> ans(n);
    for (pi p : v)
        ans[p.F - 1] = p.S;
    if (!ans[0] && n > 1)
        ans[0] = 1;
    for (int x : ans)
        cout << x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
