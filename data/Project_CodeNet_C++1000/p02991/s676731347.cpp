#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ep emplace_back
#define st first
#define sc second

using namespace std;

const ll mod = 998244353;
const int e = 1e6+69;
const int base = 311;
// dung igt thay cho gt luc tinh giai thua
//
// cach tao hoan vi tu n so : n*(n+1)/2;

vector<ll>cur;
vector<ll>adj[e];
ll dist[e];

ll st, ed;

void djk()
{
    queue<ll>q;
    q.push(st);
    while(q.size() != 0)
    {
        ll x = q.front();
        q.pop();
        for(auto j : adj[x])
        {
            if(dist[j] > dist[x] + 1)
            {
                dist[j] = dist[x] + 1;
                q.push(j);
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=3*n + 69; i++)
    {
        dist[i] = 1e18;
    }
    for(int i=1; i<=k; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b + n);
        adj[a+n].pb(b + 2*(n));
        adj[a + 2*(n )].pb(b);

    }
    cin >> st >> ed;
    dist[st] = 0;
    djk();
    if(dist[ed] == 1e18) cout << -1;
    else cout << dist[ed]/3;

}
