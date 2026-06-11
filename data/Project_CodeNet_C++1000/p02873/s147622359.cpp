#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18
int main()
{
    string s;
    cin >> s;
    ll n = s.length();
    ll left[n + 2];
    ll right[n + 2];
    right[n] = 0;
    ll count = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == '>')
        {
            count++;
            right[i] = count;
        }
        else
        {
            count = 0;
            right[i] = 0;
        }
    }

    left[0] = 0;
    count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '<')
        {
            count++;
            left[i + 1] = count;
        }
        else
        {
            count = 0;
            left[i + 1] = 0;
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        ans = ans + max(left[i], right[i]);
    }
    cout << ans << "\n";

    return (0);
}
