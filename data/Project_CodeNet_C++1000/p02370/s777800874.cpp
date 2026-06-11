#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <list>

using namespace std;
#define  INF  (INT_MAX/2)
#define  MAXV  10001
#define  MAXE 100001
#define  NIL  -1

list<int> ans;
bool vis[MAXV];
int head[MAXE], indegree[MAXV];
int cnt;

struct Edge {
  int  to, next=NIL;
} edge[MAXE];

void bfs(int u){
  queue<int> q;
  vis[u] = true;
  q.push(u);
  while (!q.empty()){
    u = q.front();
    ans.push_back(u);
    q.pop();

    for (int i=head[u];i!=NIL;i=edge[i].next){
      u=edge[i].to;
      if (!vis[u] && --indegree[u] == 0){
	vis[u] = true;
	q.push(u);
      }
    }
  }
}

void tpSort(int n){
  for (int i = 0; i < n; ++i) {vis[i] = false;}
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0 && !vis[i]) {bfs(i);}
  }
}

void add(int u, int v){
  edge[cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}

int main(void){
  int V, E, s, t;
  cin >> V >>E;
  cnt = 0;
  memset(head,NIL,sizeof(int)*(E+1));

  for (int i = 0; i < E; ++i){
    cin >> s>>t;
    indegree[t]++;
    add(s, t);
  }

  tpSort(V);
  for (list<int>::iterator itr=ans.begin(); itr!=ans.end();itr++){cout << *itr <<endl;}

  return 0;
}
