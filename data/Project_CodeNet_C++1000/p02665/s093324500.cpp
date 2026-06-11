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
  vector<ll> sup(n+1,0);
  for (int i = n-1; i > 0; --i)
  {
    sup[i]=sup[i+1]+a[i+1];
  }

  vector<ll> b(n+1);
  b[0]=1-a[0];
  if (b[0]<0) {
    cout<<-1<<endl;
    return 0;
  }
  for (int i = 1; i < b.size(); ++i)
  {
    b[i]=min(2*b[i-1]-a[i],sup[i]);
    if (b[i]<0||b[i-1]>a[i]+b[i]|| a[i]+b[i]>2*b[i-1]) {
      cout<<-1<<endl;
      return 0;
    }
  }
  // for(auto&& e: b) 
  // {
  //   cout<<e<<" ";
  // }
  // cout<<endl;

  cout<<accumulate(a.begin(), a.end(),0LL)+accumulate(b.begin(), b.end(),0LL)<<endl;
}