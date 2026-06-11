#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

typedef pair<int, int> pint;
typedef pair<pint, pint> Data ;

int N, M, Q; 
vector<int> V, a, b, c, d;
int ans = 0;

void dfs(const int depth, const int max_v) {
  if(depth == N) {
    int work = 0;
    REP(i,Q) {
      if(V[b[i]] - V[a[i]] == c[i]) work += d[i];
    }
    if(work > ans) ans = work;
  } else {
    for(int v = V[depth-1]; v <= max_v; v++) {
      V[depth] = v;
      dfs(depth+1, max_v);
    }
  }
}

int main() {
  cin>>N>>M>>Q;
  a = vector<int>(Q);
  b = vector<int>(Q);
  c = vector<int>(Q);
  d = vector<int>(Q);
  REP(i,Q) {
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  }
  V = vector<int>(N+2, 0);
  V[0] = 1;
  V[1] = 1;
  V[N+1] = M;
  for(int i = 1; i <= M; i++) {
    V[N] = i;
    dfs(2, i);
  }
  cout << ans << endl;
  return 0;
}
