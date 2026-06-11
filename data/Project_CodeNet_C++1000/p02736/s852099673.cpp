//
// Created by Ильдар Ялалов on 14.01.2020.
//
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")



#ifdef zxc

#include <random>
#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <array>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_map>
#include <stack>

#else
#include <bits/stdc++.h>
#endif


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double dbl;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
typedef unsigned int uint;


#ifdef zxc

#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


bool debug = 0;
const int MAXN = 1e6 + 100;
const int LOG = 20;
const int mod = 998244353;
const int MX = (1e7);
typedef long long li;

int cnt[MAXN];

int get_C(int n, int k) {
    int val = cnt[n] - cnt[k] - cnt[n - k];
    debug(n,k, val);
    if (val >= 1)
        return 2;
    return 1;
}

int calc(vector<int> &a) {
    int res = 0;
    int n = sz(a);
    for (int i = 0; i < n; ++i) {
        res += (get_C(n-1, i) ) * a[i];
        debug(i, a[i],res);
    }
    res = (res & 1);
    debug(res);
    return res;
}

void solve() {
    for (int i = 1; i < MAXN; ++i) {
        cnt[i] = cnt[i - 1];
        int x = i;
        while (x % 2 == 0) {
            x = x / 2;
            cnt[i]++;
        }
    }
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        c[i] = x - '1';
    }
    auto a = c;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = (a[i] & 1);
    }
    debug(a);
    debug(b);

    int val = calc(b);
    if (val == 1) {
        cout << 1 << "\n";
        return;
    }
    for (auto &x : a) {
        if (x == 1) {
            cout << 0;
            return;
        }
        x = x / 2;
    }

    int res = calc(a);
    if (res & 1) {
        cout << 2 << "\n";
    } else {
        cout << 0 << "\n";
    }


}


signed main() {
#ifdef zxc
    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#else
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(15);

    int t = 1;
    while (t--)
        solve();


    debug(1.0 * clock() / CLOCKS_PER_SEC);
}


