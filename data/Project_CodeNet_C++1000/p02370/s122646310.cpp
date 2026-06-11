#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
constexpr auto INF = 2147483647;
typedef long long ll;

static const int MAX = 100000;
vector<int> adjGraph[MAX];
list<int> ans;
bool check[MAX];
int N;
int indeg[MAX];

void bfs(int start){
  queue<int> que;
  que.push(start);
  check[start] = true;
  while(!que.empty()){
    int u = que.front(); 
    que.pop();
    ans.push_back(u);
    rep(i,adjGraph[u].size()){
      int v = adjGraph[u][i];
      indeg[v]--;
      if(indeg[v] == 0 && !check[v]){
        que.push(v);
        check[v] = true;
      }
    }
  }
}

void tpSort(){
  rep(i,N) indeg[i] = 0;
  rep(u,N){
    rep(i,adjGraph[u].size()){
      int v = adjGraph[u][i];
      indeg[v]++;
    }
  }
  
  rep(u,N){
    if(indeg[u] == 0 && !check[u])bfs(u);
  }
  for(auto itr = ans.begin();itr != ans.end(); itr++){
    cout << *itr << endl;
  }
  
}


int main(){

  int s,t ,M;
  cin >> N >> M;

  rep(i,N) check[i] = false;

  rep(i,M){
    cin >> s >> t;
    adjGraph[s].push_back(t);
  }
  tpSort();

  return 0;
}
