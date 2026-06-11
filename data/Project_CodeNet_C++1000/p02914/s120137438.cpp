#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define pb push_back
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n" // interactive problem
#define int long long

const int N = (int)(5e5) + 322;
const int inf = (int)(1e9) + 123;
const int mod = (int)(1e9) + 7;
const double EPS = 1e-9;

int n, a[N];
unsigned long long allxor;

const int LOG_A = 62;

int basis[LOG_A + 1];

void insertVector(int mask) {
    for (int i = LOG_A - 1; i >= 0; i--) {
        if ((mask & 1ll << i) == 0) continue;

        if (!basis[i]) {
            basis[i] = mask;
            return;
        }

        mask ^= basis[i];
    }
}

signed main() {
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        allxor ^= a[i];
    }
    //cout << allxor << endl;
    int change = 0;
    for(int i = 0; i < LOG_A; ++i) {
        if (!((allxor >> i) & 1ll)) {
            change |= (1ll << i);
        }
    }
    for(int i = 1; i <= n; ++i) {
        a[i] &= change;
        insertVector(a[i]);
    }
    unsigned long long ans = 0;

    for (int i = LOG_A - 1; i >= 0; i--) {
        if (!basis[i]) continue;

        if (ans & 1ll << i) continue;

        ans ^= basis[i];
    }

    cout << ans * 2ll + allxor << endl;


    return 0;
}