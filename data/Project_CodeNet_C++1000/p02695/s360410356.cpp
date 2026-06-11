#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

struct Query {
  int a,b,c,d;
};
int n,m,q;
vector<Query> query;


struct Node {
  int depth;
  vector<int> A;
  int calc_point() {
    int point=0;
    for(const auto& e: query) {
      if (A[e.b]-A[e.a]==e.c) point+=e.d;
    }
    return point;
  }
};
map<vector<int>,bool> seen;
int ans=0;
void dfs(Node now) {
  // 到達を記録
  seen[now.A]=true;
  // 到達したときにしたい処理を追加

  // N個の要素が集まったら，
  if (now.depth==n-1) {
    // for(const auto& e: now.A) {
    //   cout<<e<<" ";
    // }
    // cout<<now.calc_point()<<endl;
    // 完成したAについてqueryを試してpointを計算
    ans=max(ans,now.calc_point());
    return;
  }

  // 今いる点から行ける候補について
  for (int i = 0; i <= m-now.A.back(); ++i)
  {
    Node nxt=now;
    nxt.depth+=1;
    nxt.A.push_back(now.A.back()+i);
    if (seen[nxt.A]) continue;
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
    Node start;
    start.depth=0;
    start.A.push_back(i);
    dfs(start);
  }
  cout<<ans<<endl;
}