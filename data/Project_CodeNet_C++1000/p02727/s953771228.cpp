#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<ll> p(a);
    rep (i, a)
        cin >> p[i];

    vector<ll> q(b);
    rep (i, b)
        cin >> q[i];

    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());

    vector<ll> ans;
    rep (i, x)
        ans.push_back(p[i]);
    rep (i, y)
        ans.push_back(q[i]);
    rep (i, c)
    {
        ll r;
        cin >> r;
        ans.push_back(r);
    }

    sort(ans.begin(), ans.end(), greater<ll>());
    cout << accumulate(ans.begin(), ans.begin() + x + y, 0LL) << endl;
    return 0;
}