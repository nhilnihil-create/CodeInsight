#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5;
char s[2 * N + 5];
ll a[2 * N + 5], d[2 * N + 5];
const ll mod = 1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    getchar();
    ll offset = 0;
    d[0] = 1;
    for (ll i = 1; i <= n * 2; i++)
    {
        scanf("%c", &s[i]);
        a[i] = (s[i] == 'W' ? 0 : 1);
        d[i] = a[i] ^ a[i - 1] ^ (d[i - 1] == 0);
    }
    /*
    for (ll i = 1; i <= n * 2; i++)
    {
        cout << a[i];
    }
    cout << endl;
    for (ll i = 1; i <= n * 2; i++)
    {
        cout << d[i];
    }
    */

    ll cnt = 0ll;
    ll ans = 1ll;
    for (ll i = 1; i <= n * 2; i++)
    {
        if (d[i] == 1)
        {
            cnt++;
        }
        else
        {
            if (cnt <= 0)
            {
                cout << 0;
                return 0;
            }
            ans = ans * cnt % mod;
            cnt--;
        }
    }
    if (cnt > 0)
    {
        cout << 0;
        return 0;
    }
    for (ll i = n; i >= 1; i--)
    {
        ans = ans * i % mod;
    }
    cout << ans;
}