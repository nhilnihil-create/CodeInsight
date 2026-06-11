#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  int N, K;
  cin >> N >> K;
  Graph G(N);
  for( int i = 0; i < N-1; i++ ){
    int A, B;
    cin >> A >> B;
    A--; B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  int ans = K;
  vector<bool> seen(N, 0);
  queue<int> que;

  //1段目
  que.push(0);
  seen[0] = 1;
  int num = 0;
  for( int nv : G[0] ){
    if( seen[nv] ) continue;
    que.push(nv);
    seen[nv] = 1;
    int kake = max(0LL, K-1-num);
    ans *= kake;
    ans %= MOD;
    num++;
  }

  //2段目以降
  while( !que.empty() ){
    int v = que.front();
    que.pop();
    num = 0;
    for( int nv : G[v] ){
      if( seen[nv] ) continue;
      que.push(nv);
      seen[nv] = 1;
      int kake = max(0LL, K-2-num);
      ans *= kake;
      ans %= MOD;
      num++;
    }
  }
  cout << ans << endl;

}
