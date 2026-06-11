#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long ans = -1e18;

    ans = max(ans, a * c);
    ans = max(ans, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);

    cout << ans << endl;
}