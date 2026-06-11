#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    deque<ll> d;
    rep(i, n)
    {
        d.push_back(a[i]);
    }
    ll ans = 0;
    vector<P> x;
    while (d.size() > 1)
    {
        ll a = d.front();
        ll b = d.back();
        d.pop_front();
        d.pop_back();
        if (d.size())
        {
            if (d.front() > 0)
            {
                d.push_front(a - b);
                x.push_back(P(a, b));
            }
            else
            {
                d.push_back(b - a);
                x.push_back(P(b, a));
            }
        }
        else
        {
            ans = b - a;
            x.push_back(P(b, a));
        }
    }
    cout << ans << endl;
    rep(i, n - 1)
    {
        cout << x[i].first << " " << x[i].second << endl;
    }
}