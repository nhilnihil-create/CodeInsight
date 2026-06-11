#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
  if(a==0) return b;
  return gcd(b%a,a);
}
int32_t main()
{
  int t,n,i,j,k,l=0,max1=0;
  cin>>n;
  int a[n+1];
  for(i=1;i<=n;i++) cin>>a[i];
  sort(a+1,a+n+1);
  k=a[n];
  map<int,int> m;
  for(i=1;i<=n;i++) m[a[i]]++;
  bool hi=true;
  bool dp[k+1];
  memset(dp,1,sizeof(dp));
  dp[1]=dp[0]=0;
  for(i=2;i<=k;i++)
  {if(dp[i]){
  for(j=i*i;j<=k;j+=i)
    dp[j]=0;}
    }
  for(i=2;i<=k;i++)
  { l=0;
    if(dp[i]){
     for(j=i;j<=k;j+=i)
     {
       if(m.count(j))
         l+=m[j];
      }
      if(l>1)
      {
        hi=false;
        break;
        }
        }
  }
  
  if(hi) cout<<"pairwise coprime";
  else
  {
    l=a[1];
    for(i=2;i<=n;i++)
    {
      l=gcd(l,a[i]);
    }
    if(l==1) cout<<"setwise coprime";
    else cout<<"not coprime";
  }
}
