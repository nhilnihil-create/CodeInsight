#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  ll n,k;
  cin>>n>>k;
  ll hun=500;
  if(n*hun>=k)
  {
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }
  return 0;
}