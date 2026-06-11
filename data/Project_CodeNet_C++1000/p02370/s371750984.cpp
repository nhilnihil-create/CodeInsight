#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
#define MAX 1000000
#define INF (INT_MAX/2)

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s){
  queue<int> que;
  que.push(s);
  V[s] = true;
  while(!que.empty()){
    int u = que.front(); que.pop();
    out.push_back(u);
    for(int i = 0; i < G[u].size(); i++){
      int v = G[u][i];
      indeg[v]--;
      if(indeg[v] == 0 && !V[v]){
        V[v] = true;
        que.push(v);
      }
    }
  }
}

void topological_sort(){
  for(int i = 0; i < N; i++){
    indeg[i] = 0;
  }

  for(int u = 0; u < N; u++){
    for(int i = 0; i < G[u].size(); i++) indeg[G[u][i]]++;
  }

  for(int u = 0; u < N; u++) if(indeg[u] == 0 && !V[u]) bfs(u);

  for(list<int>::iterator it = out.begin(); it != out.end(); it++){
    cout << *it << endl;
  }
}

int main(void){
  ios_base::sync_with_stdio(0);
  int s, t, M;
  cin >> N >> M;

  for(int i = 0; i < N; i++) V[i] = false;

  for(int i = 0; i < M; i++){
    cin >> s >> t;
    G[s].push_back(t);
  }

  topological_sort();
  return 0;
}