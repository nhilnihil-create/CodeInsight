/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod   998244353
#define PI 2*acos(0.0)
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};

ll bigmod(ll x, ll p)
{
    ll res = 1;
    while(p)
    {
        if(p&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        p >>= 1;
    }
    return res;
}

//=============================================ASIFAZAD==============================================//

int32_t main()
{
    io;
    int n, m;
    cin>>n>>m;
    vi val(n+1), adj(n+1);
    for(int i = 1; i<=n; i++)cin>>val[i];

    vector<bool> vis(n);


    while(m--)
    {
        int u,v;
        cin>>u>>v;
        if(val[u] > val[adj[v]])
            adj[v] = u;
        if(val[v] > val[adj[u]])
            adj[u] = v;
    }

    int ans = 0;
    for(int i = 1; i<= n;i++)
        if(val[i] > val[adj[i]])
            ans++;
    cout<<ans;
    return 0;
}