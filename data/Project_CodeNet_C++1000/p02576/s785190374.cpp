#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n,x,t;
  cin>>n>>x>>t;
  int ans=(n/x)*t;
  if (n%x!=0)
  {
    ans+=t;
  }
  cout<<ans;
  return 0;
}