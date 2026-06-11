#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  int arr[t];
  int cnt=0;
  for(int i=1;i<=t;i++)
  {
    cin>>arr[i];
  } 
  for(int i=1;i<=t;i+=2)
  {
    if(arr[i]%2 ==1)
      cnt++;
  } 
  cout<<cnt;
  return 0;
}
