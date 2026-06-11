#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
   ll l , r;
   cin>>l>>r;
   if( r -l >= 2019 )
   {
       cout<<0;
       return 0;
   }
   ll ans = INT_MAX;
   for(int i=l;(i<=l + 2019 && i<=r) ;i++   )
   {
       for(int j = i+1; (j<= l+2019 && j<= r) ; j++ )
       {
           ll temp =( (i%2019 )*( j%2019) )%2019;
           ans = min( ans , temp );
       }
   }
   cout<<ans;
}