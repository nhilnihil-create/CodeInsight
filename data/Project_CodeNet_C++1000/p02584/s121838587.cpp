#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);

    ll ans, temp = min(k, x / d);
    x -= temp * d;
    k -= temp;
    if (k % 2)
        ans = abs(x - d);
    else
        ans = x;

    cout << ans << endl;
    return 0;
}
