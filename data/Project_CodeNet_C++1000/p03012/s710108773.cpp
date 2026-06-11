#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   ll n;
   cin>>n;
   ll arr[n];
   ll sum1{0};
   for(ll i=0;i<n;i++)
   {
      cin>>arr[i];
      sum1 += arr[i];
   }
   ll ans{LONG_MAX};
   ll sum2{};
   for(ll i=0;i<n;i++)
   {
      sum2 += arr[i];
      sum1 -= arr[i];
      ans = min(ans,abs(sum1 - sum2));
   }
   cout<<ans;
   return 0;
}
