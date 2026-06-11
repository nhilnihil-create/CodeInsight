#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll ans = 0;
string s;
ll fact(ll n)
{
    ll sum = 0;
    for (ll i = n; i > 0; i--)
    {
        sum += i;
    }
    return sum;
}
int main()
{

    cin >> s;
    ll j, l, r;
    // cout << "length: " << s.length() << endl;
    for (ll i = 0; i < s.length(); i++)
    {
        j = i;
        l = 0;
        r = 0;
        while (s[j] == '<')
        {
            r++;
            j++;
        }
        while (s[j] == '>')
        {
            l++;
            j++;
        }
        // cout << l << "," << r << endl;
        if (l > r)
        {
            ans += fact(l);
            ans += fact(r - 1);
        }
        else
        {
            ans += fact(l - 1);
            ans += fact(r);
        }
        // cout << ans << endl;
        i += (l + r) - 1;
    }
    cout << ans << endl;
    return 0;
}
