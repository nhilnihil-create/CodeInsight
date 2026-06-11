#include <bits/stdc++.h>
using namespace std;

const int inf = 1e5;
int dp[101][101];

signed main () {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    string t1, t2;
    for (int i = 0; i < a; ++i) {
        t1 += '1';
        t2 += '0';
    }
    for (int i = 0; i < w - a; ++i) {
        t1 += '0';
        t2 += '1';
    }
    for (int i = 0; i < b; ++i)
        cout << t1 << '\n';
    for (int i = 0; i < h - b; ++i) 
        cout << t2 << '\n';
}
