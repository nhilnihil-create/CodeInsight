
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

  ll n;
  cin>>n;
  ll arr[n+5]={0};
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  ll cnt=0;
  ll ans=INT_MIN;
  for(int i=0;i<n-1;i++)
  {
      if(arr[i]>=arr[i+1])
      {
          cnt++;
          ans=max(ans,cnt);
      }
      else
      {
          ans=max(ans,cnt);
          cnt=0;
      }
  }
  ans=max(ans,cnt);

  cout<<ans<<endl;

}








