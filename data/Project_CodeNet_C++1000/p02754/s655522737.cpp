#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll q = n / (a + b);
    ll r = n % (a + b);
    ll ans = q * a + min(a, r);
    cout << ans << endl;
    return 0;
}