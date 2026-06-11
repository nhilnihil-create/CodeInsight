#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int t,n,i,j,k,l,l1;
  cin>>n;
 if(n&1)
  cout<<"0";
 else
 {
   if(n<10) cout<<"0";
   else
   { int s=0;
     for(i=10;i<=n;i=i*5)
     {
       s+=(n/i);
     }
     cout<<s;
   }
 }
}