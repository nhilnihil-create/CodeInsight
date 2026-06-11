#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int a[200001],b[200001],c[200001],i,j,n,ans,rep;
  long long int k;
  cin>>n>>k;
  for(i=1;i<=n;i++){cin>>a[i];b[i]=0;c[i]=0;}
  ans=0;
  i=1;
  while(1)
  { 
    if(b[i]==0){b[i]=1;c[i]=ans;}
    else{rep=ans-c[i];break;}
    i=a[i];
    ans++;
    if(ans==k){cout<<i;return 0;}
  }
  k=k-c[i];
  k=k%rep;

  for(j=0;j<k;j++){i=a[i];}
  cout<<i;
  
  
  
}