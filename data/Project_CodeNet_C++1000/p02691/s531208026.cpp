#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   int n;
   cin>>n;
   vector<int> v(n+1);
   map<ll,ll> mp;
   for(int i=1;i<=n;i++)
   {cin>>v[i];
       mp[i-v[i]]++;
   }
   ll ans=0;
   for(int i=1;i<=n;i++)
   {
       ans+=mp[i+v[i]];
   }
   cout<<ans<<endl;
   return 0;
}