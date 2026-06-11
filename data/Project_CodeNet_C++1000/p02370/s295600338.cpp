#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10000;
int n, color[MAX], indeg[MAX];
vector<int> v, DAG[MAX];

void bfs(int s);

void topologicalSort(){
  for(int i=0;i<n;i++){
    color[i] = 0;
  }
  for(int i=0;i<n;i++){
    if(color[i] == 0 && indeg[i] == 0){
      bfs(i);
    }
  }
}

void bfs(int s){
  queue<int> q;
  q.push(s);
  color[s] = 1;

  while(!q.empty()){
    int u = q.front(); q.pop();
    v.push_back(u);

    for(int i=0;i<DAG[u].size();i++){
      int w = DAG[u][i];
      indeg[w]--;
      if(indeg[w] == 0 && color[w] == 0){
        q.push(w);
        color[w] = 1;
      }
    }
  }
}

int main(){
  int e;
  cin >> n >> e;
  int s, t;
  for(int i=0;i<e;i++){
    cin >> s >> t;
    DAG[s].push_back(t);
    indeg[t]++;
  }

  topologicalSort();

  for(int i=0;i<n;i++) cout << v[i] << endl;
  return 0;
}

