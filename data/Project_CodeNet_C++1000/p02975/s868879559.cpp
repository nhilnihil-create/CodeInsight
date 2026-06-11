#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1);





int main() 
{
  ll N; cin>>N;
  map<ll,ll> mp;
  vector<ll> list;
  rep(i,N)
  {
    ll a; cin>>a;
    if(mp.count(a))
    {
      mp.at(a)++;
      continue;
    }
    mp[a]=1;
    list.push_back(a);
  }
  if(mp.size()==1&&mp.count(0)) {cout<<"Yes"<<endl; return 0;}
  if(mp.size()==2&&mp.count(0)&&N==mp.at(0)*3) {cout<<"Yes"<<endl; return 0;}
  if(mp.size()==3)
  {
    ll a=mp.at(list.at(0));
    ll b=mp.at(list.at(1));
    ll c=mp.at(list.at(2));
    if(a==b&&b==c&&(list.at(0)^list.at(1))==list.at(2))
    {
      cout<<"Yes"<<endl; return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}