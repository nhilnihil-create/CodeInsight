#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{ ll t,n,m,i,a[23],b[23],c[23],sum=0;
  cin>>n;
  for(i=1;i<=n;i++)cin>>a[i];
  for(i=1;i<=n;i++)cin>>b[i];
  for(i=1;i<=n-1;i++)cin>>c[i];
  sum+=b[a[1]];
for(i=2;i<=n;i++)
{ if(a[i]!=a[i-1]+1)
  sum+=b[a[i]];
  else
    sum+=b[a[i]]+c[a[i]-1];

 } cout<<sum;}




















