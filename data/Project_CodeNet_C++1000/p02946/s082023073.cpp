#include<iostream>
#include<math.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  if(n>1)
  {
      int l=m-n+1;
      int r=m+n-1;
      for(int i=l; i<=r; i++)
      {
          cout<<i<<" ";
      }
      
  }
  else
  cout<<m;
}