#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int N, M, Q;
vector<int> a, b, c, d;
ll ans = 0;
vector<int> A;

void dfs(int idx, int pre){
  if(idx == N){
    ll sum = 0;
    REP(i, Q){
      if(A[b[i]] - A[a[i]] == c[i]){
        sum += d[i];
      }
    }
    ans = max(ans, sum);
    return;
  }
  FOR(i, pre, M+1){
    A[idx] = i;
    dfs(idx+1, i);
  }
}

int main(){
  cin >> N >> M >> Q;
  a.resize(Q), b.resize(Q), c.resize(Q), d.resize(Q);
  A.resize(N);
  REP(i, Q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }
  dfs(0, 1);
  cout << ans << endl;
  return 0;
}