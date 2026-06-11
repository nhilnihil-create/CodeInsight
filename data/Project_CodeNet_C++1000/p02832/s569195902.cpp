#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
  if(a==0) return b;
  else return gcd(b%a,a);
}
int32_t main()
{
  int t,n,i,j,k,l,l1;
  cin>>n;
  int a[n+1];
  for(i=1;i<=n;i++) cin>>a[i];
  j=1;
  for(i=1;i<=n;i++)
  {
    if(a[i]==j)
    {
      j++;
    }
  }
  if(j==1) cout<<"-1";
  else 
  cout<<n-(j-1);
}