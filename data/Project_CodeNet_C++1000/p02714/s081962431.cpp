#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const ll MOD = 1000000007;
using namespace std;

int main(void)
{
    ll n;
    string s;
    map<char, ll> mp;
    mp['R'] = 0;
    mp['G'] = 0;
    mp['B'] = 0;
    cin >> n >> s;
    rep(i, 0, n) mp[s[i]]++;
    if (mp.size() != 3)
        cout << 0 << endl;
    else
    {

        ll ans = 1;
        for (auto i : mp)
            ans *= i.second;
        ll cta = 0;

        rep(i, 0, n)
        {
            rep(j, i + 1, n)
            {
                if (j + (j - i) >= n)
                    continue;
                if (s[i] != s[j] && s[j] != s[j + (j - i)] && s[j + (j - i)] != s[i])
                    cta++;
            }
        }
        cout << ans - cta << endl;
    }
}