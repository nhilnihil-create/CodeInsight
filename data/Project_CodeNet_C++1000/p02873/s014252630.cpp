#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  string s;
  cin>>s;
  ll ans=0;
  vector<ll> left(s.size()+1),right(s.size()+1);
  left[0]=0;
  right.back()=0;
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i]=='>') left[i+1]=0;
    else left[i+1]=left[i]+1;
  }
  for (int i = s.size()-1; i >= 0; --i)
  {
    if (s[i]=='<') right[i]=0;
    else right[i]=right[i+1]+1;
  }
  
  for (int i = 0; i < s.size()+1; ++i)
  {
    ans+=max(left[i],right[i]);
  }
  cout<<ans<<endl;
}