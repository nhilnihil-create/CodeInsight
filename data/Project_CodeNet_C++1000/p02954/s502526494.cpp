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
  string S; cin>>S;
  ll N=S.size();
  queue<ll> que;
  vector<ll> ans(N);
  rep(i,N-1)
  {
    if(S.at(i)=='R'&&S.at(i+1)=='L')
    {
      que.push(i+1);
    }
    /*
    if(S.at(i)=='L'&&S.at(i+1)=='R')
    {
      que.push(i+1);
    }
    */
  }
  rep(i,N)
  {
    if(i>que.front()&&S.at(i)=='R') {que.pop();}
    if(S.at(i)=='R')
    {
      if((que.front()-i)%2==0)
      {
        ans.at(que.front())++;
        continue;
      }
      ans.at(que.front()-1)++;
    }
    if(S.at(i)=='L')
    {
      if((i-que.front())%2==0)
      {
        ans.at(que.front())++;
        continue;
      }
      ans.at(que.front()-1)++;
    }
  }
  rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    cout<<ans.at(i);
  }
  cout<<endl;
  return 0;
}