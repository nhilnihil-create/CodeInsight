#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize ("-O3")
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double PI = 3.14159265358979323846;  /* pi */

int main() {
    int l, r, d;
    cin >> l >> r >> d;
    int ans = r / d - (l-1) / d;
    cout << ans;
    return 0;
}