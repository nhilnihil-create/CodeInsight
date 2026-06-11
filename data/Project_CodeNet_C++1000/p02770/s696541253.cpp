#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000000000
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;

ll powa(ll a, ll b, ll c)
{
    a%=c;
    if(a<0)
	a+=c;
    ll res = 1;
    while(b>0)
    {
        if(b&1)
            res*=a, res%=c;
        a*=a, a%=c;
        b>>=1;
    }
    return res;
}

#define N 200005
 
ll fact[N];
ll ifact[N];

ll ncr(ll n, ll r)
{
    if(r>n)
        return 0;
    ll ans = fact[n];
    ans*=ifact[r];
    ans%=mod;
    ans*=ifact[n-r];
    ans%=mod;
    return ans;
}
int main()
{
   FAST/**/
   
   fact[0] = 1;
   for(ll i=1;i<N;i++)
        fact[i] = fact[i-1]*i, fact[i]%=mod;
   for(ll i=0;i<N;i++)
        ifact[i] = powa(fact[i],mod-2,mod);
   
   ll k,q;
   cin>>k>>q;
   ll arr[k];
   rep(k)
        cin>>arr[i];
   while(q--)
   {
       ll n,x,m;
       cin>>n>>x>>m;
       
       ll arr1[k];
       rep(k)
            arr1[i] = arr[i]%m;
       ll sum = 0;
       rep(k)
            sum+=arr1[i];
       
       ll pref[k];
       pref[0] = arr1[0];
       for(ll i=1;i<k;i++)
            pref[i] = pref[i-1] + arr1[i];
       
       ll rem = (n-1)%k;
       
       ll mini = (x%m);
       ll maxi = (x%m) + (sum*((n-1)/k));
       if(rem>0)
            maxi += pref[rem-1];
       //cout<<"maxi = "<<maxi<<"\n";
       ll st = 1;
       ll en = maxi/m;
       ll tot = en - st + 1;
       ///cout<<"tot = "<<tot<<"\n";
       tot = max(0ll,tot);
       ll ans = n-1-tot;
       rep(k)
       {
            if(arr1[i] == 0)
            {
                if(n-1-i-1<0)
                    continue;
                ll temp = (n-1-i-1)/k;
                //cout<<"temp = "<<temp<<"\n";
                temp = temp+1;
                temp = max(temp,0ll);
                ans-=temp;
            }
       }
       cout<<ans<<"\n";
       
   }
   
   return 0;        
}  
   