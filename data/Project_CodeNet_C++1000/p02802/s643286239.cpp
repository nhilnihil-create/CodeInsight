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

  ll n,m;
  cin>>n>>m;
  vector<string> a(n+1,"NA");
  vector<ll> count(n+1);
  ll ac=0;
  ll wa=0;
  for(ll i=0;i<m;i++)
  {
    ll num;
    string s;
    cin>>num>>s;
    if(a[num]=="AC")
      continue;
    a[num]=s;
    if(s=="AC")
    {
      ac++;
      wa+=count[num];
    }
    else
    {
      count[num]++;
    }
  }

  cout<<ac<<" "<<wa<<endl;

  return 0;
}