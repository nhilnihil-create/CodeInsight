#include<bits/stdc++.h>
using namespace std;
void solve()
{
int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  long long ans=0;
  int maxx=0;
  for(int i=0;i<n;i++)
  { 
    maxx=max(maxx,arr[i]);
    ans+=maxx-arr[i];
  }
  cout<<ans<<endl;
  
  
}
int main()
{
solve();
}
