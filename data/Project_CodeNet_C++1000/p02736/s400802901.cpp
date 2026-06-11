// O O O O O O O O O O O O O O O OO O OO O OO O O O TTCH O TTTCH O TTTCH O O O O
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
// #include <random>
#include <iomanip>
#include <bitset>
#include <cassert>
 
using namespace std;

#define int long long
#define y1 y11
#define double long double
#define less less228
#define left left228
#define right right228
#define list list228
#define all(v) v.begin(), v.end()
 
 
 
template<typename T> void uin(T &a, T b) {
    if (b < a) a = b;
}
template<typename T> void uax(T &a, T b) {
    if (b > a) a = b;
}

const int N = 1000 * 1000 + 228;

int a[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
        a[i] -= 1;
    }
    int par = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] & 1) {
            par ^= (((n - 1) & (i - 1)) == (i - 1));
        }
    }
    if (par & 1) {
        cout << 1 << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 1) {
                cout << 0 << endl;
                return 0;
            }
        }
        par = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] >>= 1;
            if (a[i]) {
                par ^= (((n - 1) & (i - 1)) == (i - 1));
            }
        }
        if (par == 1) cout << 2 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
// RU_023
 
/*
5
1 3 4 2 3 
3
1 5 3
4 3 2
2 4 2
-------
2


7
5 6 2 3 6 7 6
5
7 7 5
3 3 7
3 7 10
1 7 6
4 7 8
-------
16

*/