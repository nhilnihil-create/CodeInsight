#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef vector<int> vi;

signed main()
{
    string s;
    cin >> s;
    int mod = 2019;
    reverse(s.begin(), s.end());
    vi rem(mod);
    rem[0]++;
    int p = 1, suf = 0;
    int ans = 0;
    for (auto c:s)
    {
        (suf += (c-'0') * p) %= mod;
        ans += rem[suf];
        (p *= 10) %= mod;
        rem[suf]++;
    }
    cout << ans << "\n";
}