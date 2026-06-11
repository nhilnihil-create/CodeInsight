#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    ll h;
    cin >> h;

    ll ans = 0;
    ll rate = 1;

    while (h > 0)
    {
        ans += rate;
        rate <<= 1;
        h >>= 1;
    }
    cout << ans << endl;
}