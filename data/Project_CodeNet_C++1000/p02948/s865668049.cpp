#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<P> p;
    rep(i, n)
    {
        double a, b;
        cin >> a >> b;
        p.push_back(P(a, b));
    }
    sort(p.begin(), p.end());
    priority_queue<ll> q;
    q.push(0);
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j < n && p[j].first <= i)
        {
            q.push(p[j].second);
            j++;
        }
        ans += q.top();
        q.pop();
        q.push(0);
    }
    cout << ans << endl;
    return 0;
}