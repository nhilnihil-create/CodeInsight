#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  long long int i,j,k,n,a[100001],b[100000],ans;
  cin>>n;
  ans=0;
  for(i=0;i<=n;i++){cin>>a[i];}
  for(i=0;i<n;i++){cin>>b[i];}
  
  for(i=0;i<n;i++)
  {
    if(a[i]>=b[i]){ans+=b[i];}
    else if(a[i]+a[i+1]>=b[i])
    {
      a[i+1]=a[i+1]+a[i]-b[i];
      ans+=b[i];
    }
    else
    {
      ans=ans+a[i]+a[i+1];
      a[i+1]=0;
    }
            
  }
  cout<<ans;
}