#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
  cin>>n;
  
  long long arr[n];
  long long ans=1;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int count=0;
  for(int i=0;i<n;i++)
  {
      if(arr[i]==0)
      count++;
  }
  if(count>0)
  {
      cout<<0;
      return 0;
  }
  for(int i=0;i<n;i++)
  {
 
    if(arr[i]<= 1000000000000000000/ans)
    {
      ans*=arr[i];
    }
    else
    {
        
        cout<<-1;
        return 0;
    }
  }
 cout<<ans;
  
}