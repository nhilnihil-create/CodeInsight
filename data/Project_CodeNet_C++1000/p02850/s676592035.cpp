#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int n;
  cin>>n;
  vector<vector<int>> graph(n);
  vector<pair<int,int>> edge(n-1);
  for (int i = 0; i < n-1; ++i)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    edge[i]=make_pair(a,b);
  }
  int k=graph[0].size();
  for (int i = 1; i < n; ++i)
  {
    k=max(k,(int)graph[i].size());
  }
  map<pair<int,int>,int> edge_color;
  vector<int> umbillical(n);
  umbillical[0]=-1;
  vector<bool> seen(n,false);
  queue<int> next;
  seen[0]=true;
  next.push(0);
  while(!next.empty())
  {
    int start=next.front();
    next.pop();
    set<int> used_color;
    used_color.insert(umbillical[start]);
    int c=0;
    for (int j = 0; j < graph[start].size(); ++j)
    {
      int goal=graph[start][j];
      if(seen[goal]) continue;
      if(c==umbillical[start]) c++;
      edge_color[make_pair(start, goal)]=c;
      umbillical[goal]=c;
      seen[goal]=true;
      next.push(goal);
      c++;
    }
  }
  cout<<k<<endl;
  for (int i = 0; i < edge.size(); ++i)
  {
    cout<<1+edge_color[edge[i]]<<endl;
  }


}