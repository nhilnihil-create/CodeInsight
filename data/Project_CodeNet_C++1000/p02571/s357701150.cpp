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

void solve() {
    string s, t;
    cin >> s >> t;
    dbg << s.size() << endl;
    dbg << t.size() << endl;

    int lo = 1000000;
    for (int i = 0; i + t.size() <= s.size(); ++i) {
        int changes = 0;
        dbg << "i = " << i << endl;
        for (int j = 0; j < t.size(); ++j) {
            dbg << "\tj = " << j << endl;
            if (s[j + i] != t[j]) ++changes;
            dbg << "\tchanges = " << changes << endl;
        }
        if (changes < lo) lo = changes;
    }
    cout << lo << endl;
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
