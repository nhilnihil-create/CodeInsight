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
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;

ll hold[1000005];

ll get(string s)
{
    ll n = s.length();
    //ll par = 0;
    ll arr[n];
   rep(n)
        arr[i] = ((ll)s[i]-'0');
   
   ll par = (arr[0]);
   rep(n)
   {
       if(i == 0)
            continue;
       ll diff = i;
       ll st = i;
       ll cnt = hold[n-1] - hold[n-1-i] - hold[i];
       if(cnt>0)
            continue;
       par^=((arr[i]));
   }
   return par;
            
}

int main()
{
   FAST/**/
   
   for(ll i=0;i<1000005;i++)
   {
       ll temp = i;
       ll cnt = 0;
       while(temp>0)
       {
           temp/=2;
           cnt+=temp;
       }
       hold[i] = cnt;
   }
   
   ll n;
   cin>>n;
   
   string s;
   cin>>s;
   
   ll arr[n];
   rep(n)
        arr[i] = ((ll)s[i]-'0');
   
   ll par = (arr[0]%2);
   rep(n)
   {
       if(i == 0)
            continue;
       ll diff = i;
       ll st = i;
       ll cnt = hold[n-1] - hold[n-1-i] - hold[i];
       //cout<<"for "<<n-1<<" C "<<i<<" = "<<cnt<<"\n";
       if(cnt>0)
            continue;
       par^=((arr[i]%2));
   }
   
   if(par == 1)
   {
       cout<<par;
       return 0;
   }
   
   string s1;
       rep(n-1)
       {
           ll temp = ((ll)s[i]-'0') - ((ll)s[i+1] - '0');
           temp = abs(temp);
           s1+=char('0'+temp);
       }
       //s = s1;
       //n = s.length();
  
   map<ll,ll> ma;
   rep(n)
        ma[(ll)s[i] - '0'] = 1;
   if(ma.size() == 1)
   {
       cout<<0;
       return 0;
   }
   
   if(ma.size() == 2)
   {
       if(ma[1]>0 && ma[2]>0)
       {
           cout<<0;
           return 0;
       }
       if(ma[1]>0 && ma[3]>0)
       {
           cout<<get(s1);
           return 0;
       }
       if(ma[2]>0 && ma[3]>0)
       {
           cout<<get(s1);
           return 0;
       }
   }
   
   cout<<0;
   
  
   
   return 0;        
}  
   
