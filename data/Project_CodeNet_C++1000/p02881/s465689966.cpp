#include<iostream>
using namespace std;
int main (void)
{
  long long int i,j,n,ans;
  cin>>n;
  i=1;
  
  while(1)
  {
    j=n/i;
    if(i*j==n){ans=i+j-2;}
    if(i>j)break;
    i++;
  }
  cout<<ans;
}