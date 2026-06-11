#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int main()
{
    int x, y, ans = 0;
    cin >> x >> y;
    if (x * y == 1)
        ans += 400000;
    if (x == 1)
        ans += 300000;
    if (y == 1)
        ans += 300000;
    if (x == 2)
        ans += 200000;
    if (y == 2)
        ans += 200000;
    if (x == 3)
        ans += 100000;
    if (y == 3)
        ans += 100000;

    cout << ans << endl;
}