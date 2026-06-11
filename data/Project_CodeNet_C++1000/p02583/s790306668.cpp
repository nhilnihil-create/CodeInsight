#include<bits/stdc++.h> 
#define ll long long 
#define pb push_back 
#define vec vector<int> 
#define fo(i,n) for (ll i = 0; i < n; i++)
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second 
using namespace std;  
int main()
{


   ll n;
   cin>>n;
   vector<ll> v(n);
   fo(i,n)
   {
       cin>>v[i];
   }
   int count=0;
  fo(i,n)
  {
      for(ll j=i+1;j<n;j++)
      {
          for(ll k=j+1;k<n;k++)
          {
              if(v[i]+v[j]>v[k]
              && v[j]+v[k]>v[i]
              && v[k]+v[i]>v[j]
              && i<j<k && v[i]!=v[j] && v[j]!=v[k] && v[k]!=v[i])
            // cout<<i<<j<<k<<endl;
              //cout<<v[i]<<v[j]<<v[k]<<endl;
              count++;
          }
      }
     
  }
 cout<<count;
}