#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);


int N,M,Q;
vector<vector<int>> A(0);




int main() 
{
  cin>>N>>M>>Q;
  stack<pair<int,vector<int>>> stk;
  rep(i,M)
  {
    stk.push({1,{i+1}});
  }
  while(!stk.empty())
  {
    auto p=stk.top();
    stk.pop();
    int n=p.first;
    auto vec=p.second;
    if(n==N) {A.push_back(vec); continue;}
    int l=vec.at(n-1);
    for(int i=l;i<=M;i++)
    {
      auto vec2=vec;
      vec2.push_back(i);
      stk.push({n+1,vec2});
    }
  }  
  /*
  for(auto a:A)
  {
    rep(i,a.size())
    {
      if(i!=0) cout<<" ";
      cout<<a.at(i);
    }
    cout<<endl;
  } 
  */
  vector<int> a(Q);
  vector<int> b(Q);
  vector<int> c(Q);
  vector<int> d(Q);
  rep(i,Q)
  {
    cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  
  int ans=0;
  for(auto hoge:A)
  {
    int sum=0;
    rep(i,Q)
    {
      if(hoge.at(b.at(i))-hoge.at(a.at(i))==c.at(i))
      {
        sum+=d.at(i);
      }
    }
    ans=max(sum,ans);
  }
  
  cout<<ans<<endl;
  
  return 0;
}

