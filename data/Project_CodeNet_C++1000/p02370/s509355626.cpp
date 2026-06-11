#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int V,E,cnt[10000];
  vector<int> G[10000],ans;
  scanf("%d %d",&V,&E);
  fill(cnt,cnt+V,0);
  for(int i=0;i<E;i++){
    int s,t;
    scanf("%d %d",&s,&t);
    G[s].push_back(t);
    cnt[t]++;
  }
  queue<int> q;
  for(int i=0;i<V;i++){
    if(cnt[i]==0) q.push(i);
  }
  while(!q.empty()){
    int v = q.front(); q.pop();
    ans.push_back(v);
    for(int i=0;i<G[v].size();i++){
      cnt[G[v][i]]--;
      if(cnt[G[v][i]]==0) q.push(G[v][i]);
    }
  }
  for(int i=0;i<V;i++) printf("%d\n",ans[i]);
  return 0;
}