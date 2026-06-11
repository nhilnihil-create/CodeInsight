#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main()
{
    IOS;
   //freopen("inputfile.txt","r",stdin);
   ll n,m;cin>>n>>m;
   ll ar[n];
   for(ll i=1;i<=n;i++)cin>>ar[i];
   ll count = 0;
   set<ll> v[n+1];
   while(m--)
   {
       ll a,b;cin>>a>>b;
       v[a].insert(b);
       v[b].insert(a);
   }
    for(ll i=1;i<=n;i++)
   {
       bool flag = true;
      for(auto x:v[i])
      {

          if(ar[i]<=ar[x])
          {
              flag = false;
             break;
          }
      }
      if(flag==true)count++;
   }
   cout<<count<<endl;
    return 0;
}
//<!...........ALHAMDULILLAH.............!!>>

