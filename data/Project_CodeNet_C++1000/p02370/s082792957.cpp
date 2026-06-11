#include<bits/stdc++.h>
using namespace std;

static const int MAX = 100000;
static const int INF = (1<<29);
int N,M;
vector< int > G[MAX];
bool V[MAX];
int indeg[MAX];
list< int > out;

void bfs(int num){
  queue<int> que;
  que.push(num);
  while(!que.empty()){
    int now = que.front(); que.pop();
    out.push_back(now);
    for(int i=0;i<G[now].size();i++){
      int v = G[now][i];
      indeg[v]--;
      if(indeg[v] == 0 && !V[v]){
	V[v] = true;
	que.push(v);
      }
    }
  }
}

void tsort(){
  for(int i=0;i<N;i++){
    indeg[i] = 0;
    V[i] = false;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<G[i].size();j++) indeg[G[i][j]]++;
  }
  for(int i=0;i<N;i++){
    if(indeg[i] == 0 && !V[i]) bfs(i);
  }
  for(list<int>::iterator it = out.begin();it != out.end();it++){
    cout << *it << endl;
  }
}

int main(){
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int s,t; cin >> s >> t;
    G[s].push_back(t);
  }
  tsort();
}