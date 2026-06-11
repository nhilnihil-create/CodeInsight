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
    int d, t, s;
    cin >> d >> t >> s;
    if (s * t >= d) cout << "Yes" << endl;
    else cout << "No" << endl;
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
