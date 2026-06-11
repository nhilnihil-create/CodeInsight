#include <bits/stdc++.h>
using namespace std;

const int64_t lot = 1000000000;

signed main () {
    int64_t s;
    cin >> s; 
    int64_t x = (lot - (s % lot)) % lot, y = (s + x) / lot;
    cout << 0 << ' ' << 0 << ' ' << lot << ' ' << 1 << ' ' << x << ' ' << y << '\n';
}
