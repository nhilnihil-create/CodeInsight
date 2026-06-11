#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define pii pair<ll,ll>
#define inf 1000000000000000000
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

#define N 1000005

int main()
{
  FAST/**/
   
   ll n;
   cin>>n;
   
   ll arr[n];
   rep(n)
        cin>>arr[i];
   
   ll fr[N];
   memset(fr,0,sizeof(fr));
   
   rep(n)
        fr[arr[i]]++;
        
   ll fr1[N];
   memset(fr1,0,sizeof(fr1));
        
   bool nono = 0;
   for(ll i=N-1;i>1;i--)
   {
       for(ll j=i;j<N;j+=i)
            fr1[i]+=fr[j];
       if(fr1[i]>1)
       {
           nono = 1;
           break;
       }
   }
   
   ll g = 0;
   rep(n)
        g = __gcd(arr[i],g);
   
   if(nono == 0)
   {
       cout<<"pairwise coprime";
       return 0;
   }
   
   if(g == 1)
   {
       cout<<"setwise coprime";
       return 0;
   }
   
   cout<<"not coprime";
   
   
   
   return 0;        
}  

  
          
   