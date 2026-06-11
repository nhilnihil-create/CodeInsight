#include<bits/stdc++.h>
using namespace std;
int fun( int mid, int k,vector< int>&arr)
{
     int ans=0;
    for( int i=0;i<arr.size();i++)
    {
        if(arr[i]>mid)
        ans+=(arr[i]  / mid) ;
    }
    if(ans<=k)
    return 1;
    return 0;
}
int main()
{
   int n,k;
  cin>>n>>k;
  vector< int>arr(n);
  int mn=1;
 int mx=-1;
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
      mx=max(mx,arr[i]);
  }
  
  while(mn<=mx)
  {
       int mid=(mn+mx)/2;
      if(fun(mid,k,arr))
      mx=mid-1;
      else 
      mn=mid+1;

  }
  if(fun(mn,k,arr))
  cout<<mn;
  else
  cout<<mn-1;
  return 0;
}