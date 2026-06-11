#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll a, b, k; cin >> a >> b >> k;
    ll xx = a - k;

    if (xx < 0) cout << 0 << ' ' << (b - abs(xx) >= 0 ? b - abs(xx) : 0);
    else cout << a - k << ' ' << b;
}