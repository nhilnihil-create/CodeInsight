#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

struct Query {
  int a,b,c,d;
};
int n,m,q, ans=0;
vector<Query> query;


void dfs(vector<int> now) {
  if (now.size()==n) {
    int point=0;
    for (const auto& e: query) {
      if (now[e.b]-now[e.a]==e.c) point+=e.d;
    }
    ans=max(ans,point);
    return;
  }
  // 広義単調増加列より末尾以上の要素は追加可能
  for (int i = now.back(); i <= m; ++i)
  {
    vector<int> nxt=now;
    nxt.push_back(i);
    dfs(nxt);
  }
}

int main()
{
  cin>>n>>m>>q;
  query.resize(q);
  for(auto&& e: query) 
  {
    cin>>e.a>>e.b>>e.c>>e.d;
    e.a--;
    e.b--;
  }
  for (int i = 1; i <= m; ++i)
  {
    vector<int> start{i};
    dfs(start);
  }
  cout<<ans<<endl;
}