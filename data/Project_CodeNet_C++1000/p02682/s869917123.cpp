#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
ll a, b, c, k, ans, mn;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> k;
    mn = min(a, k);
    ans += mn;
    k -= mn;
    mn = min(b, k);
    k -= mn;
    mn = min(c, k);
    ans -= mn;
    cout << ans;
    return 0;
}
