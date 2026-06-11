#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int n,a[21],b[21],c[20],i,j,k,ans;
  cin>>n;
  ans=0;
  
  for(i=1;i<=n;i++){cin>>a[i];}
  
  for(i=1;i<=n;i++){cin>>b[i];}
  for(i=1;i<n;i++){cin>>c[i];}
  ans=0;
  for(i=1;i<n;i++)
  {
   ans+=b[a[i]];
   if(a[i+1]-a[i]==1){ans+=c[a[i]];}
  }
  ans+=b[a[n]];
  cout<<ans<<endl;
}