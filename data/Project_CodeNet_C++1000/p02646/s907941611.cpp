#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int t,n,i,j,k,l,l1,a,v,b,w;
  cin>>a>>v;
  cin>>b>>w;
  cin>>t;
  if(a<b)
  {
    if(v<=w) cout<<"NO";
    else
    {
      k=(b-a)/(v-w);
      if((b-a)%(v-w)==0) ;
      else k++;
      if(t>=k) cout<<"YES";
      else
       cout<<"NO";
    }
  }
  else
  {
    if(v<=w) cout<<"NO";
    else
    {
      k=(a-b)/(v-w);
      if((a-b)%(v-w)==0) ;
      else k++;
      if(t>=k) cout<<"YES";
      else
       cout<<"NO";
    }
  }
}