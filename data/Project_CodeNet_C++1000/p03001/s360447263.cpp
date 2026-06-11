#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   ll w,h,x,y;
   cin>>w>>h>>x>>y;
   int flag = 0;
   if(2*x == w && 2*y == h)
      flag = 1;
   double ans = (w*h)/2.0;
   cout<<fixed<<setprecision(9)<<ans<<" "<<flag;
   return 0;
}
