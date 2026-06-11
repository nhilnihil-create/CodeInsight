#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ld H, W;
    ll ans;
    cin >> H >> W;
    if (H == 1 || W == 1) ans = 1;
    else ans = ceil(H * W / 2);
    cout << ans << endl;
}
