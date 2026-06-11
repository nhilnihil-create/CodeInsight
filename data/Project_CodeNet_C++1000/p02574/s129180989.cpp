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

int a[1000010];
int primes[1000010];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    set<int> as;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 1 && as.find(a[i]) != as.end()) {
            bad = true;
        }
        as.insert(a[i]);
    }
    int cur_g = a[0];
    for (int i = 1; i < n; ++i) {
        cur_g = gcd(cur_g, a[i]);
    }
    if (cur_g != 1) {
        cout << "not coprime" << endl;
        return;
    }
    for (int i = 2; i < 1000003; ++i) {
        if (primes[i] == 0) {
            int cnt = 0;
            if (as.find(i) != as.end()) ++cnt;
            for (int j = 2 * i; j < 1000010; j += i) {
                primes[j] = 1;
                if (as.find(j) != as.end()) ++cnt;
            }
            if (cnt > 1) {
                bad = true;
                break;
            }
        }
    }
    if (bad) {
        cout << "setwise coprime" << endl;
        return;
    }
    cout << "pairwise coprime" << endl;
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
