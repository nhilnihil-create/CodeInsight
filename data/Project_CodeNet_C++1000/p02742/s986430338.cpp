#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main (void) {
    ll H, W;
    cin >> H >> W;
    ll ans;
    if (H == 1 || W == 1) {
        ans = 1;
    } else if (H * W  % 2 == 0) {
        ans = (H * W) / 2;
    } else {
        ans = (H * W) / 2 + 1;
    }
    cout << ans <<endl;
}