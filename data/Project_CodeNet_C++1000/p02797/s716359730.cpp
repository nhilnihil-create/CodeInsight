#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n,k,s;
  cin>>n>>k>>s;
  for (int i = 0; i < k; ++i)
  {
    cout<<s<<" ";
  }
  for (int i = k; i < n; ++i)
  {
    if(s==1e9) cout<<1<<" ";
    else cout<<s+1<<" ";
  }

}