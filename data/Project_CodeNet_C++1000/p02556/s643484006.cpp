#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define f first
#define s second
const int N = 2e5+5;

ll n;
vector< pair<ll,ll> > v;
priority_queue< pair<ll,ll> > q , q2 , q3 , q4;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        ll x,y;
        cin >> x >> y;
        v.push_back({x , y});
        q.push({x+y , i-1});
        q2.push({-x+y , i-1});
        q3.push({x-y , i-1});
        q4.push({-x-y , i-1});
    }

    ll ans=0;
    for(int i=0; i<v.size(); i++)
    {
        ll x = v[i].f , y = v[i].s;
        pair<ll,ll> tmp;

        if (q.top().s==i)
        {
            tmp = q.top();
            q.pop();
        }
        ll tmp2 = q.top().f;
        if (q.size() != n) q.push(tmp);
        ans = max(ans , tmp2-x-y);

        if (q2.top().s==i)
        {
            tmp = q2.top();
            q2.pop();
        }
        tmp2 = q2.top().f;
        if (q2.size() != n) q2.push(tmp);
        ans = max(ans , tmp2+x-y);

        if (q3.top().s==i)
        {
            tmp = q3.top();
            q3.pop();
        }
        tmp2 = q3.top().f;
        if (q3.size() != n) q3.push(tmp);
        ans = max(ans , tmp2-x+y);

        if (q4.top().s==i)
        {
            tmp=q4.top();
            q4.pop();
        }
        tmp2 = q4.top().f;
        if (q4.size() != n) q4.push(tmp);
        ans = max(ans , tmp2+x+y);
    }

    cout << ans << '\n';

    return 0;
}