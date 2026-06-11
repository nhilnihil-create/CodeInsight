
/*
g++ --std=c++17 A.cpp
*/

#include <iostream>
#include <iomanip> //! for setprecision(20)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;
using mint = static_modint<MOD>;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    dsu d(n);

    rep(i, q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else if (t == 1) {
            cout << (d.same(u, v) ? 1 : 0) << endl;
        }
    }

    return 0;
}
