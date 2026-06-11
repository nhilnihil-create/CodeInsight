#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector <int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)

int main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n; cin >> n;
    int fact[n];
    fact[0] = 1;
    FOR(i, 1, n) {
        fact[i] = fact[i-1]*i;
    }
    int p = 0;
    int q = 0;
    int b = (1 << n) - 1;
    REP(i, n) {
        int tmp; cin >> tmp;
        b ^= (1 << (tmp-1));
        int bit = 0;
        REP(j, tmp-1) {
            bit |= (1 << j);
        }
        p += __builtin_popcount(b & bit) * fact[n-1-i];
    }
    b = (1 << n) - 1;
    REP(i, n) {
        int tmp; cin >> tmp;
        b ^= (1 << (tmp-1));
        int bit = 0;
        REP(j, tmp-1) {
            bit |= (1 << j);
        }
        q += __builtin_popcount(b & bit) * fact[n-1-i];
    }
    int ret = (p < q) ? q-p : p-q;

    cout << ret << "\n";
}
