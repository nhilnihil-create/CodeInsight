
#include <iostream>
#include <iomanip> //! for setprecision(10)
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

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;

bool know[12][12];


bool match(const vector<int>& lhs, const vector<int>& rhs)
{
    if (lhs.size() != rhs.size()) return false;
    rep(i, lhs.size()) {
        if (lhs[i] != rhs[i]) return false;
    }
    return true;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> p(n), q(n), t(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    rep(i, n) t[i] = i+1;

    int pOrd = -1;
    int qOrd = -1;
    int ord = 0;
    do {
        if (pOrd < 0 && match(p, t)) pOrd = ord;
        if (qOrd < 0 && match(q, t)) qOrd = ord;
        ++ord;
    } while ((pOrd < 0 || qOrd < 0) && next_permutation(t.begin(), t.end()));

    cout << abs(pOrd - qOrd) << endl;

    return 0;
}
