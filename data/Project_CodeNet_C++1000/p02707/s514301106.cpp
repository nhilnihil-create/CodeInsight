#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main()
{
   IOS;
   //freopen("inputfile.txt","r",stdin);
   ll n;cin>>n;
   map<ll,ll> ma;
   for(ll i=0;i<n-1;i++)
   {
       ll x;cin>>x;
       ma[x]++;
   }
   for(ll i=1;i<=n;i++)
   {
       cout<<ma[i]<<endl;
   }
    return 0;
}
//<!...........ALHAMDULILLAH.............!!>>

