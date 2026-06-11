#include<bits/stdc++.h> 

using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  int arr[]={1,2,3};
  int res=0;
  for(int i=0;i<3;i++)
  {
    if(arr[i]!=a&&arr[i]!=b){
      cout<<arr[i];
      return 0;
    }
  }
  return 0;
}