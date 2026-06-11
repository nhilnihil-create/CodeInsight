#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0;i < N;i++)
#define pb push_back

int main()
{
  vector<int>E[10005];
  int flag[10005] = {0};
  int indeg[10005] = {0};
  vector<int>out;
  int N,M,s,t;
  cin >> N >> M;
  while(M--) {
    cin >> s >> t;
    E[s].pb(t);
  }
  Rep(i,N) {
    Rep(j,E[i].size()) {
      int v = E[i][j];
      indeg[v]++;
    }
  }
  Rep(p,N) {
    if(!flag[p] && indeg[p] == 0) {
      
      queue<int>que;
      que.push(p);
      flag[p] = true;
      while(!que.empty()) {
	int v = que.front(); que.pop();
	out.pb(v);
	Rep(i,E[v].size()) {
	  int nv = E[v][i];
	  indeg[nv]--;
	  if(indeg[nv] == 0 && !flag[nv]) {
	    flag[nv] = true;
	    que.push(nv);
	  }
	}
      }
      
    }
  }
  Rep(i,N) {
    cout << out[i] << endl;
  }
  return 0;
}