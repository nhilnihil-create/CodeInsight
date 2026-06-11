#include<bits/stdc++.h>
using namespace std;


void solve()
{
  int x,n;
  cin>>x>>n;
  if(n==0)
  {
      cout<<x;
      return;
  }
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

  sort(arr,arr+n);
//  int start=arr[0];
  int end=arr[n-1];
  int ans=abs(x-arr[0]+1);
  int ref=arr[0]-1;
  
//int ref;
  for(int i=0;i<n-1;i++)
  {  
     for(int j=arr[i]+1;j<arr[i+1];j++)
     {
       if(ans>abs(x-j))
       {
       ref=j;
       ans=abs(x-j);
       //continue;
       }
     }
  }
 if(ans>abs(x-(arr[n-1]+1)))
  {
   ans=abs(x-(arr[n-1]+1));
 ref=arr[n-1]+1;
  }
 
  cout<<ref;
}
int main()
{
solve();
}
