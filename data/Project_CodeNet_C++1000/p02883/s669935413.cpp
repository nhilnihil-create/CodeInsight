#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,k;
   cin >> n >> k;
   vector<ll> a(n),f(n);
   for(int i = 0;i<n;i++)cin >> a[i];
   for(int i = 0;i<n;i++)cin >> f[i];
   sort(a.begin(),a.end());
   sort(f.rbegin(),f.rend());
   ll sum = 0;
   for(auto i:a)sum += i;
   if(sum<=k)
   {
      cout<<0<<endl;
      return 0;
   }
   ll l = 0,r = 1e18;
   while(1)
   {
      ll m = (l+r)/2;

      ll now = 0;
      for(int i = 0;i<n;i++)
      {
         now += max(0LL,a[i]-m/f[i]);
      }
      if(k<now)l = m;
      else r = m;
      if(r-l<2)break;
   }
   cout<<r<<endl;
}