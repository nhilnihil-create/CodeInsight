#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans = w*h/2;
    printf("%.10f\n", ans);
    if (x == w/2 && y == h/2) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}