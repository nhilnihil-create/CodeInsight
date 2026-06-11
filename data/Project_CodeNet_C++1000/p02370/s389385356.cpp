#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int main(){
  int s,t,n,m;
  cin>>n>>m;

  vector<vector<int> > lis(n+1000);
  list<int> out;  
  vector<bool> V(n+1000,false);
  for(int i=0;i<m;i++){
    cin>>s>>t;
    lis[s].push_back(t);  
  }
  
  //ここから本番
  vector<int> indeg(n+1000,0);

  //隣接リストを参照して、入次数の数を数える
  for(int u=0;u<n;u++){
    for(int i=0;i<lis[u].size();i++){
      int v=lis[u][i];
      indeg[v]++;
    }
  }

  for(int u=0;u<n;u++){
    if(indeg[u]==0 && !V[u]){
      //幅優先探索
      queue<int> que;
      que.push(u);
      V[u]=true;
      while(!que.empty()){
        int u=que.front(); que.pop();
        out.push_back(u);
        for(int i=0;i<lis[u].size();i++){
          int v=lis[u][i];
          indeg[v]--;
          if(indeg[v]==0 && !V[v]){
            V[v]=true;
            que.push(v);
          }
        }
      }
    }
  }

  for(auto it=out.begin();it!=out.end();it++){
    cout<<*it<<'\n';
  }
  return(0);
}
