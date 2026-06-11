#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  } 
   int ans=1000000000;
   for(int i=1;i<=100;i++)
   {
    int temp=0;
    for(int j=0;j<n;j++)
    {
     temp+=(arr[j]-i)*(arr[j]-i);
    }
    ans=min(temp,ans);
   }
   cout<<ans<<endl;
   return 0;
} 