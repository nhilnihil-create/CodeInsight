#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    long long W, H, x, y;
    cin >> W >> H >> x >> y;
    double res = (double)(W)*H / 2;
    cout << fixed << setprecision(10) << res << " ";

    if(x * 2 == W && y * 2 == H)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}