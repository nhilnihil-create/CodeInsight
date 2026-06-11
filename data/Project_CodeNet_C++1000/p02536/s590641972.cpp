#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i,n) for( ll i=0 ; i<n ; i++ )
#define f(i, a, b) for( ll i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
#define MOD 1000000007

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll digits(ll n)
{
    return floor(log10(double(n))) + 1;
}
ll SieveOfEratosthenes(ll n)
{
    vector<bool>prime(n+1);
    int ans = 0;
    for(int i =0; i<=n; i++)
        prime[i] = true;
    prime[1] = false;
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for(int i = 2; i<=n; i++)
    {
        if(prime[i])
        {
            ans++;
        }
    }
    return ans;
}
void permute(string a, int l, int r)
{
    if (l == r)
    {
        cout<<a<<endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
        }
    }
}

ll maxpower(ll n,ll k)
{
    ll count = 0;
    while(n>0)
    {
        n = n/k;
        if(n>0)
            count++;
    }
    return count;
}
vector<int>adj[100001];
vector<bool>vis(100001,false);
void dfs(ll x)
{
    if(!vis[x])
    {
        vis[x] = true;
        for(auto v : adj[x])
        {
            dfs(v);
        }
    }
}
int32_t main()
{
    faster();
    ll n,m;
    cin>>n>>m;
    fi(i,m)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    for(int i =1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans - 1;


}

