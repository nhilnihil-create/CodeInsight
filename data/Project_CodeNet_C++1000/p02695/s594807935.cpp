#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int N, M, Q;
vector<vector<int>> v;
int ret;

void dfs(int i, int mn, vector<int>& w){
  if(i == N){
    int sum = 0;
    rep(j,Q){
      if(w[v[j][1]] - w[v[j][0]] == v[j][2]){
        sum += v[j][3];
      }
    }
    ret = max(ret, sum);
    return;
  }
  REP(ii,mn,M+1){
    w[i] = ii;
    dfs(i+1, ii, w);
  }
}


int main(){
  cin >> N >> M >> Q;
  rep(i,Q){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    v.push_back({a,b,c,d});
  }

  ret = 0;
  
  vector<int> w(N);
  dfs(0, 1, w);

  cout << ret << endl;
  
  return 0;
}

