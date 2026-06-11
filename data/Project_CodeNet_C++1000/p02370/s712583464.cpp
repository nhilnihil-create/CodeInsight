#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0;i < N;i++)
#define pb push_back

vector<int>E[10005];
int N;
bool flag[10005] = {0};
vector<int>out;

void dfs(int v) {
  flag[v] = true;
  Rep(i,E[v].size()) {
    int nv = E[v][i];
    if(!flag[nv])dfs(nv);
  }
  out.pb(v);
}

int main()
{
  int M,s,t;
  cin >> N >> M;
  while(M--) {
    cin >> s >> t;
    E[s].pb(t);
  }
  Rep(i,N) {
    if(!flag[i])dfs(i);
  }
  reverse(out.begin(),out.end());
  Rep(i,N)cout << out[i] << endl;
  return 0;
}