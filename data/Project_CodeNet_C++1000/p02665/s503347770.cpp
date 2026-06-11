#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n;
  cin>>n;
  vector<ll> a(n+1);
  for(auto&& e: a) 
  {
    cin>>e;
  }

  vector<ll> nodes(n+1);
  nodes.back()=a.back();
  for (int i = n-1; i >= 0; --i)
  {
    nodes[i]=nodes[i+1]+a[i];
  }

  vector<ll> ans=nodes;
  ans[0]=1;
  for (int i = 1; i < nodes.size(); ++i)
  {
    if (ans[i-1]-a[i-1]<0) {
      cout<<-1<<endl;
      return 0;
    }
    ans[i]=min(nodes[i],2*(ans[i-1]-a[i-1]));
  }
  if (ans.back()!=a.back()) cout<<-1<<endl;
  else cout<<accumulate(ans.begin(), ans.end(),0LL)<<endl;
}