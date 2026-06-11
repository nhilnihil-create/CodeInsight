#include <bits/stdc++.h>
using namespace std;

int N,M; //頂点と辺の数
vector<vector<int>> G; //グラフ
vector<int> h; //入次数
vector<int> l_depth; //最大経路長
vector<int> ans; //答えを格納

void input(){
  cin>>N>>M;
  G.resize(N);
  h.resize(N, 0);
  int f,t;
  for(int i=0; i<M; i++){
    cin>>f>>t;
    //f--; t--;
    G[f].push_back(t);
    h[t]++;
  }
}

void topoBFS(){   
  queue<int> unchecked;
  for(int i=0; i<N; i++){
    if(h[i]==0){
      unchecked.push(i);
      l_depth[i] = 0;
    }
  }
  while(!unchecked.empty()){
    int current = unchecked.front();
    unchecked.pop();
    ans.push_back(current);

    for(int next: G[current]){
      h[next]--;
      l_depth[next] = max(l_depth[next], l_depth[current]+1); //最長経路長
      if(h[next]==0){
        unchecked.push(next);
      }
    }
  }
}

int main(){
  input();

  l_depth.resize(N, -1);
  topoBFS();

  bool isDAG = ans.size()==N; //DAGであるかどうか
  if(isDAG){
    for(int x: ans){
      cout<<x<<endl;
    }
  }else{
    cout<<"DAGではない"<<endl;
  }
}
