#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int N = 1e6 + 1;
signed main () {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    for (int i = 1;;i++) if (x * i % 360 == 0) return cout << i, 0;
}
