#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    ll cta = 0;
    vector<pair<char, ll>> v;
    char tmp = s[0];
    rep(i, 0, s.length() + 1)
    {
        if (tmp != s[i])
            v.push_back({s[i - 1], cta}), cta = 1, tmp = s[i];
        else
            cta++;
    }
    ll ans = 0;

    if (v[0].first == '<')
    {

        for (ll i = 0; i < v.size(); i += 2)
        {
            ll a, b = 0;
            a = v[i].second - 1;
            if (i + 1 < v.size())
                b = v[i + 1].second - 1;
            ans += max(a + 1, b + 1) + (a + 1) * a / 2 + (b + 1) * b / 2;
        }
    }
    else
    {
        ans += (v[0].second + 1) * v[0].second / 2;
        for (ll i = 1; i < v.size(); i += 2)
        {
            ll a, b = 0;
            a = v[i].second - 1;
            if (i + 1 < v.size())
                b = v[i + 1].second - 1;
            ans += max(a + 1, b + 1) + (a + 1) * a / 2 + (b + 1) * b / 2;
        }
    }
    cout << ans << endl;
}