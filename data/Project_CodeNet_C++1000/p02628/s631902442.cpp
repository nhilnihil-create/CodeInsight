#include<bits/stdc++.h>
using namespace std;
void solve()
{
  int n,k;
  cin>>n>>k;
  int arr[n];
  
  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  sort(arr,arr+n);
  long long ans=0;
  for(int i=0;i<k;i++)
    ans+=arr[i];
  
  cout<<ans<<endl;
}

int main()
{
solve();
}