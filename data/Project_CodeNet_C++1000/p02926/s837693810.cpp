// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define emb emplace_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <typename T> inline T range(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
 
inline void setin(string s) {
    freopen(s.c_str(), "r", stdin);
}
 
inline void setout(string s) {
    freopen(s.c_str(), "w", stdout);
}
 
template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}
 
template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

#define int long long

const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 1e2 + 15;
int n;
pii a[N];

main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    // setin("input.txt");
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].f >> a[i].se;
    sort(a + 1, a + 1 + n, [&](pii a, pii b) {
        return atan2(a.f, a.se) < atan2(b.f, b.se);
    });
    for(int i = 1; i <= n; ++i)
        a[i + n] = a[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        pii cur(0, 0);
        for(int j = i; j <= i + n - 1; ++j) {
            cur.f += a[j].f;
            cur.se += a[j].se;
            Max(ans, cur.f * cur.f + cur.se * cur.se);
        }
    }
    cout.precision(30);
    cout << sqrt(ans) << endl;
    return 0;
}