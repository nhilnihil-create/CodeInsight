#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    if (k <= a)
        cout << a - k << " " << b << endl;
    else
        cout << 0 << " " << max(ll(0), b - k + a) << endl;
}