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

void solve();

int main() {
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

#define ld double
#define int long long

const int maxN = 2e5 + 10, maxK = 1e4 + 10, inf = 1e15 + 10, mod = 999999, base = 223;

int x;

void solve() {
    cin >> x;
    for (int i = 1; i < 1000000; i++) {
        if ((360 * i) % x == 0) {
            cout << (360 * i) / x;
            return;
        }
    }
}