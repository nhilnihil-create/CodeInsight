#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i,j;
  cin>>n;
  long long int a[n];
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int count=0,maxi=0;
  
  for(i=0;i<n;i++)
  {
    count=0;
    while(i+1<n && a[i+1]<=a[i])
    {
      i++;
      count++;
    }
    maxi=max(maxi,count);
  }
  
  cout<<maxi;
}