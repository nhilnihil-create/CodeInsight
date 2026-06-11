// #pragma GCC optimize("Ofast")

// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
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
#include <random>
#include <iomanip>
#include <bitset>

using namespace std;

template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}

template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}
#define left left228
#define right right228
#define ld long double
#define list list228
// #define prev prev228
#define mp make_pair
#define list list228
#define all(v) v.begin(), v.end()


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    if (n & 1) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if ((i & 1)) {
            if (s[i] != 'i') {
                cout << "No\n";
                return 0;
            }
        } else {
            if (s[i] != 'h') {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}

/*
3
1 1 2
2 2 2
3 3 2
2 1 1
3 2 1


2 2
1 1 2
2 2 2
1 2 3
2 1 1

2
2 1 2 2 3
2 2 2 1 1

бархатом обитый гроб
5
1 2
2 3
3 4
3 5
1
2 3
1 2
4 3
2 3 5

*/


