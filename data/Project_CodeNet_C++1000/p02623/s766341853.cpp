#include<iostream>
using namespace std;
int main (void)
{
  long long int a[200001],b[200001],k,sum1=0,sum2=0;
  int n,m,i,j,ans=0;
  
  cin>>n>>m>>k;
  a[0]=0,b[0]=0;
  for(i=1;i<=n;i++){cin>>a[i];}
  for(i=1;i<=m;i++){cin>>b[i];sum2+=b[i];}
  j=m;
  
  for(i=0;i<=n;i++)
  {
    sum1+=a[i];
    if(sum1>k)break;
    while(sum1+sum2>k)
    {
      sum2=sum2-b[j];
      j--;
    }
    
    if(i+j>ans){ans=i+j;}
  }
  cout<<ans<<endl;
 
  return 0;
}