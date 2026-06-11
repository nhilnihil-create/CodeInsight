#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
   ll n,r;
   cin>>n>>r;
   if(n>=10)
   {
   	  cout<<r<<"\n";
   }
   else{
   	  ll conv = 100*(10-n);
   	  ll ans = r+conv;
   	  cout<<ans<<"\n";
   }
}