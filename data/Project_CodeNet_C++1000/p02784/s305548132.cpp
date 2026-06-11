#include<bits/stdc++.h>
using namespace std;
int main()
{
  int h,n;
  cin>>h>>n;

  int arr[n];
  int sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    sum=sum+arr[i];
    
  }
  if(sum>=h)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  
  
}