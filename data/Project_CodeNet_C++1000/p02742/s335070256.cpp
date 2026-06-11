#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    if (a == 1 || b == 1) cout << 1, exit(0);
    cout << (a * b + 1) / 2;
}
