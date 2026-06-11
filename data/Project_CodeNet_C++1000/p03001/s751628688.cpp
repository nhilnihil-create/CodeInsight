#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    ll W, H, x, y;

    cin >> W >> H >> x >> y;
    cout << W * H / 2.0 << ' ' << (2*x == W && 2*y == H) << endl;

    return 0;
}