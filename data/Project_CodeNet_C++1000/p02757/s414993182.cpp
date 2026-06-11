#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, p;
    string s;
    cin >> n >> p >> s;
    ll ans = 0;
    if (p == 2)
    {
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - '0') % 2 == 0)
                ans += i + 1;
        }
    }
    else if (p == 5)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' || s[i] == '5')
                ans += i + 1;
        }
    }
    else
    {
        map<int, int> mp;
        mp[0]++;
        int t = 0, power = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            t = (t + (s[i] - '0') * power) % p;
            ans += mp[t];
            mp[t]++;
            power = power * 10 % p;
        }
    }
    cout << ans << endl;
}
