#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <assert.h>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
using namespace std;

// #define __DEBUG__

#ifdef __DEBUG__
bool debug_disabled = false;
#else
bool debug_disabled = true;
#endif

#define dbg if (debug_disabled) {} else cerr

set<int> friends[200010];
int color[200010];

int visit(int a, int c) {
    color[a] = c;
    dbg << "a = " << a << ", c = " << c << endl;
    int res = 1;
    for (auto iter = friends[a].begin(); iter != friends[a].end(); ++iter) {
        int f = *iter;
        dbg << "\tf = " << f << endl;
        if (color[f] == 0) {
            res += visit(f, c);
        }
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        friends[x].insert(y);
        friends[y].insert(x);
    }
    int hi = -1;
    int c = 1;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            int res = visit(i, c);
            dbg << "res for i = " << i << ", c = " << c << " is " << res << endl;
            if (hi < res) hi = res;
            ++c;
        }
    }
    cout << hi << endl;
}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(12);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve();
    }

    return 0;
}
