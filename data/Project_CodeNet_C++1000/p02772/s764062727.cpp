#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n+1];
  bool flag=true;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(arr[i]%2==0)
    {
      if(!(arr[i]%3==0 || arr[i]%5==0))
      {
        flag=false;
        break;
        
        
      }
        
      
      
    }
    
    
  }
  if(flag)
    cout<<"APPROVED"<<endl;
  else
    cout<<"DENIED"<<endl;
  
  
}