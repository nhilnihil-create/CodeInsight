#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll p[2000005];
ll m[2000005];
ll mp[2000005];

int main()
{
   ll a;
 cin>>a;
 ll mm=1e6;
   for(ll i=0;i<a;i++){
    cin>>p[i];
    mm=max(mm,p[i]);
    mp[p[i]]++;
   }

   sort(p,p+a);

   ll n = unique(p, p+a) - p;
   ll ans=0;

   
   
   
   for(ll i=0;i<n;i++)
   {
       if(m[p[i]]==0)
       {
           if(mp[p[i]]==1)
            ans++;
            for(ll j=p[i]*2;j<=mm;j+=p[i])
            m[j]=1;

       }
   }



   cout<<ans;

    return 0;
}
