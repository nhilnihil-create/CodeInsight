#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);

/*
void make(vector<vector<int>> &A,int N,int M,vector<int> a)
{
  if(a.size()==N) {A.push_back(a); return;}
  if(a.size()==0)
  {
    rep(i,M)
    {
      make(A,N,M,{i+1});
    }
    return;
  }
  int l=a.at(a.size()-1);
  for(int i=l;i<=M;i++)
  {
    auto b=a;
    b.push_back(i);
    make(A,N,M,b);
  }
}
*/



int main() 
{
  int N,M,Q; cin>>N>>M>>Q;
  /*
  vector<vector<int>> A(0);
  make(A,N,M,{});
  for(auto a:A)
  {
    for(auto w:a)
    {
      cout<<w<<" ";
    }
    cout<<endl;
  }
  */
  queue<vector<int>> que;
  for(int i=1;i<=M;i++)
  {
    que.push({i});
  }
  while(que.front().size()<N)
  {
    auto vec=que.front();
    que.pop();
    auto l=vec.at(vec.size()-1);
    for(int i=l;i<=M;i++)
    {
      auto vec2=vec;
      vec2.push_back(i);
      que.push(vec2);
    }
  }  
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
  while(!que.empty())
  {
    auto hoge=que.front();
    que.pop();
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

