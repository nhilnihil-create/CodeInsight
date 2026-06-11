#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    ll same = 0;
    if (2*x == W && 2*y == H){
        same = 1;
    }
    cout << fixed << setprecision(20) << double(W*H)/2.0 << " " << same << endl;

    return 0;
}
