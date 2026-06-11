#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int x, y;
    cin >> x >> y;

    int prize[206]{0};
    prize[1] = 300000;
    prize[2] = 200000;
    prize[3] = 100000;

    int moni = prize[x] + prize[y];
    if (x == 1 && y == 1)
        moni += 400000;
    cout << moni << endl;
}