/*
         ██╗ ██████╗ ██╗███╗   ██╗    ██╗   ██╗███████╗
         ██║██╔═══██╗██║████╗  ██║    ██║   ██║██╔════╝
         ██║██║   ██║██║██╔██╗ ██║    ██║   ██║███████╗
    ██   ██║██║   ██║██║██║╚██╗██║    ██║   ██║╚════██║
    ╚█████╔╝╚██████╔╝██║██║ ╚████║    ╚██████╔╝███████║
     ╚════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝     ╚═════╝ ╚══════╝
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int maxn = 5e5 + 5;
const int inf = 0x3f3f3f3f;
ll st[maxn],tot;
struct lb
{
    const ll MAXL = 60;
    vector<ll> a;
    lb()
    {
        for (int i = 0; i < 64; i++)
            a.push_back(0);
    }
    void insert(ll t)
    {
        for(int i=0;i<tot;i++)
        {
            if((t>>st[i])&1)
            {
                if(a[i]) t^=a[i];
                else {a[i]=t;break;}
            }
        }
    }
    ll query_max()
    {
        ll res = 0;
        for(int i=0;i<tot;i++)
        {
            if(!((res>>st[i])&1)) res^=a[i]; 
        }
        return res;
    }
    ll query_min()
    {
        return a[0];
    }
} lb;

int main()
{
    int n;
    scanf("%d", &n);
    ll ans=0;
    vector<ll>ass;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        scanf("%lld", &x);
        ans^=x;
        ass.push_back(x);
    }
    for(int i=60;i>=0;i--)
    {
        if(!((ans>>i)&1)) st[tot++]=i;
    }
    for(auto it:ass)
    {
        lb.insert(it);
    }
    ll qaq=lb.query_max();
    // cout<<qaq<<" "<<ans<<endl;
    printf("%lld\n",qaq+(qaq^ans));
    return 0;
}