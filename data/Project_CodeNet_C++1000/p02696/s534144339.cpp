#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, n;
    cin >> a >> b >> n;

    ll ans = (a * min(b - 1, n)) / b - a * (min(b - 1, n) / b);
    cout << ans << endl;
    return 0;
}