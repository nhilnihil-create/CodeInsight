#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 10000000
// cout << "YES\n";
// cout << "NO\n";
int main()
{
    ll a, b, c, d, res = LLONG_MIN;
    cin >> a >> b >> c >> d;
    res = max({res, a * c, a * d, b * d, b * c});
    cout << res << endl;
    return 0;
}