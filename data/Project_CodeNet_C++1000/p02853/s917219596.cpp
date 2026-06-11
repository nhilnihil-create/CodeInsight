#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int X, Y;
    cin >> X >> Y;
    map<int, int> mp;
    mp[1] = 300000;
    mp[2] = 200000;
    mp[3] = 100000;
    if (X == 1 && Y == 1) {
        cout << 1000000 << endl;
    } else {
        cout << mp[X] + mp[Y] << endl;
    }
    return 0;
}