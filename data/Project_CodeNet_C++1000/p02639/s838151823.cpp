#include<bits/stdc++.h>
using namespace std;
int main()
{  
  long int n,i,k,l;
  n=5;
  long int a[n+1];
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  for(i=1;i<=n;i++)
  {
    if(a[i]==0)
      l=i;
  }
  cout<<l<<endl;

}