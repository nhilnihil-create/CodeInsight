#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, a, b, ans = 0;
    cin >> n >> a >> b;

    ans += n / (a + b) * a;

    n %= a + b;

    if (a > n)
        ans += n;
    else
        ans += a;

    cout << ans << endl;
    return 0;
}
