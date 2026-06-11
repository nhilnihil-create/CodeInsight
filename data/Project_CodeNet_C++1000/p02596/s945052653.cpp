#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int k;
    cin >> k;
    ll a = 0;
    int ans = 0;
    do
    {
        ans++;
        a *= 10;
        a += 7;
        a %= k;
        if (ans > k)
        {
            cout << -1 << endl;
            return 0;
        }
    } while (a != 0);
    cout << ans << endl;
    return 0;
}