#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i=0;i<(n);i++)
#define PB push_back
#define CLR(a) memset(a,0,sizeof a)
#define VI vector<int>
#define INT(x) int x; scanf("%d",&x);
#define SZ(a) ((int)(a.size()))

#define MAX_V 100000

int V;
VI graph[MAX_V];
bool vis[MAX_V];
VI mlist;
int indeg[MAX_V];

void topologicalsort() {
  CLR(indeg);
  REP(i, V) {
    REP (j, SZ(graph[i])) {
      int p = graph[i][j];
      indeg[p]++;
    }
  }

  REP(i, V) {
    if (indeg[i] == 0 && !vis[i]) {
      queue<int> que;
      que.push(i);
      mlist.PB(i);
      vis[i] = true;
      while (!que.empty()) {
	int p = que.front(); que.pop();

	REP(j , SZ(graph[p])) {
	  int np = graph[p][j];
	  indeg[np]--;
	  if (vis[np]) continue;
	  if (indeg[np] == 0) {
	    vis[np] = true;
	    que.push(np);
	    mlist.PB(np);
	  }
	}
      }
    }
  }
}

int main() {
  cin >> V;
  INT(E);
  REP(i, E) {
    INT(s); INT(t);
    graph[s].PB(t);
  }
  topologicalsort();

  REP(i, SZ(mlist)) {
    cout << mlist[i] << endl;
  }
}