#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int i,j,k,n,d[50],ans;
  ans=0;
  cin>>n;
  for(i=0;i<n;i++){cin>>d[i];}
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      ans=ans+d[i]*d[j]; 
    }
  }
  cout<<ans;
  
}