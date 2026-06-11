#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m;
vector<ll> ve[100005];
ll s, e;
queue<ll> qi, qu;
ll d[3][100005];

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < m; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
    }
    scanf("%lld%lld", &s, &e);
    qi.push(s), qu.push(0);
    for(ll i = 1; i <= n; i++) d[0][i] = d[1][i] = d[2][i] = -1;
    d[0][s] = 0;
    while(!qi.empty())
    {
        ll t1 = qi.front(), t2 = qu.front();
        qi.pop(), qu.pop();
        for(ll i = 0; i < ve[t1].size(); i++)
        {
            if(d[(t2 + 1) % 3][ve[t1][i]] > -1) continue;
            d[(t2 + 1) % 3][ve[t1][i]] = t2 + 1;
            qi.push(ve[t1][i]), qu.push(t2 + 1);
        }
    }
    if(d[0][e] == -1) cout<<-1<<endl;
    else cout<<d[0][e] / 3<<endl;
    return 0;
}
