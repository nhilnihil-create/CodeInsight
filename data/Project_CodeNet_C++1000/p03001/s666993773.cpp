#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    double c_w = w/2., c_h = h/2.;
    if ((double)x == c_w && (double)y == c_h) printf("%.9f 1", w*h/2.);
    else printf("%.9f 0", w*h/2.);
    return 0;
}
