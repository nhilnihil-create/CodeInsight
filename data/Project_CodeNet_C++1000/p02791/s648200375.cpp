#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i=x;i<n;i++) 
#define sort(v) sort(v.begin(),v.end());
const ll mod = 1E9+7;

int main()
{
   ll n,ans = 0;
   cin>>n;
   vector<ll> v(n), e(n);
   loop(i,0,n){
      cin>>v[i];
      if(i == 0)e[i] = v[i];
      else e[i] = min(e[i-1],v[i]);
      if(e[i] == v[i]){
         ans++;
         // cout<<i<<" ";
      }
   }
   cout<<ans<<endl;
}