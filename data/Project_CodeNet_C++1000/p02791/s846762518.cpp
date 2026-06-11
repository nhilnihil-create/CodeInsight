//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,i;
  cin>>n;
  ll arr[n];
  for(i=0; i<n; i++)
    cin>>arr[i];
  ll minm=arr[0];
  ll ans=1;
  for(i=1; i<n; i++)
  {
    if(arr[i]<minm)
    {
      ans++;
      minm=arr[i];
    }
  }
  cout<<ans;
  return 0;
}