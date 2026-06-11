#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int x, ans = 1;
    cin >> x;
    if (400 <= x && x <= 599) ans = 8;
    else if (600 <= x && x <= 799) ans = 7;
    else if (800 <= x && x <= 999) ans = 6;
    else if (1000 <= x && x <= 1199) ans = 5;
    else if (1200 <= x && x <= 1399) ans = 4;
    else if (1400 <= x && x <= 1599) ans = 3;
    else if (1600 <= x && x <= 1799) ans = 2;
    cout << ans << endl;
    return 0;
}