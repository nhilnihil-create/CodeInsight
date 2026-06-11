#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
void solve()
{
   int l,r,d,m=1,ct=0;
   cin>>l>>r>>d;
   for (int i = 1; i <=r ; ++i)
   {
     m=i*d;
     if(m>=l&&m<=r)
      ct++;
   }
  cout<<ct;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   #ifdef Pranab
   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
   #endif  
 
   int t=1; 
   //cin>>t;
 
   while(t--)
   {solve();cout<<"\n";}

   cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;

   return 0;
}