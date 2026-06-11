#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < n; ++i)

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> mp(n + 1, 0), cta(n + 1, 0);
    vector<ll> a(m);
    vector<string> s(m);
    rep(i, 0, m)
    {
        cin >> a[i] >> s[i];
    }
    ll maru = 0;
    ll batu = 0;
    rep(i, 0, m)
    {
        if (mp[a[i]] == 0) //初採点の場合
        {
            if (s[i] == "AC")
                mp[a[i]] = 2;
            else if (s[i] == "WA")
                mp[a[i]] = 1, cta[a[i]]++;
        }
        else if (mp[a[i]] == 1) //2回目以降
        {
            if (s[i] == "AC")
                mp[a[i]] = 2;
            else
                cta[a[i]]++;
        }
    }
    rep(i, 0, n + 1) if (mp[i] == 2) maru++, batu += cta[i];
    cout << maru << " " << batu << endl;
}
