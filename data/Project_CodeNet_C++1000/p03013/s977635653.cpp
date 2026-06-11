#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n,m;
  cin>>n>>m;
  set<int> broken;
  for (int i = 0; i < m; ++i)
  {
    int tmp;
    cin>>tmp;
    broken.insert(tmp);
  }
  vector<ll> pattern(n+1);
  pattern[0]=1;
  pattern[1]=
    (broken.find(1)!=broken.end())?
    0:1;
  for (int i = 2; i < pattern.size(); ++i)
  {
    if(broken.find(i)!=broken.end()) 
    {
      pattern[i]=0;
      continue;
    }
    pattern[i]=
    (pattern[i-1]+pattern[i-2])%mod;

  }
  cout<<pattern.back()<<endl;
}