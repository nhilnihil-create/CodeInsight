#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{ 
  int n,a[2000000],i,j,k;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int max1=0,max2=0;
  for(i=0;i<n;i++)
  {
    if(max1<=a[i]){max2=max1;max1=a[i];}
    else if(max2<=a[i]){max2=a[i];}
  }
  for(i=0;i<n;i++)
  {
    if(a[i]==max1){cout<<max2<<endl;}
    else{cout<<max1<<endl;}
  }
  return 0;
}