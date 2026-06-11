#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    cout << w * h / 2 << " ";
    if (x == w / 2 && y == h / 2)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}