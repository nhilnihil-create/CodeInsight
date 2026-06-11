#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  long int res=1000,stock=0;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(int i=0;i<n-1;i++)
  {
    if(arr[i]<arr[i+1]&&stock==0)
    {
      stock=res/arr[i];
      res=res%arr[i];
      continue;
    }
    if(arr[i]>arr[i+1])
    {
      res+=(arr[i]*stock);
      stock=0;
    }
  }  
  res+=(arr[n-1]*stock);
  cout<<res<<endl;
  return 0;
}    