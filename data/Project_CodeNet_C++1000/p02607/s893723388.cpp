#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  
  int arr[n+1];
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  
  int ans=0;
  
  for(int i=1;i<=n;i+=2)
    if(arr[i]%2 != 0)
      ans++;
  
  cout<<ans;
}
