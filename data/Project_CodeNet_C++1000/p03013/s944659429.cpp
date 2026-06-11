#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

//GOTU
//#GOTU

int main()
{
   ll n,m;
   cin>>n>>m;
   ll broken[n+1]{};
   ll temp;
   for(ll i=0;i<m;i++)
   {
      cin>>temp;
      broken[temp]++;
   }
   ll ways[n+1]{};
   ways[0] = 1;

   if(broken[1] == 0)
      ways[1] = 1;

   for(ll i=2;i<=n;i++)
   {
      if(broken[i] == 0)
      {
         ways[i] = ways[i-1] + ways[i-2];
         ways[i]%=mod;
      }
   }
   cout<<ways[n];
   return 0;
}
