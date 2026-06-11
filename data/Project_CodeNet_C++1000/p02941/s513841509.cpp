#include <iostream>
#include <cstdio>
#include <queue>
#define PLL pair<ll, ll>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll n;
ll a[200005], b[200005];
priority_queue<PLL> pq;
ll cnt;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
        pq.push(make_pair(b[i], i));
    }
    while(!pq.empty())
    {
        ll t1 = pq.top().F, t2 = pq.top().S;
        pq.pop();
        if(a[t2] == b[t2]) continue;
        if(b[t2] < a[t2])
        {
            printf("-1\n");
            return 0;
        }
        if(b[t2] <= b[(t2 + n - 1) % n] || b[t2] <= b[(t2 + 1) % n]) continue;
        ll t3 = b[t2] - a[t2];
        ll t4 = b[(t2 + n - 1) % n] + b[(t2 + 1) % n];
        ll t5 = (t3 + t4 - 1) / t4;
        ll t6 = b[t2] - t5 * t4;
        cnt += t5;
        if(t6 < a[t2]) t6 += t4, cnt--;
        if(t6 == b[t2]) continue;
        b[t2] = t6;
        pq.push(make_pair(b[t2], t2));
    }
    for(ll i = 0; i < n; i++)
    {
        if(b[i] != a[i])
        {
            printf("-1\n");
            return 0;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
