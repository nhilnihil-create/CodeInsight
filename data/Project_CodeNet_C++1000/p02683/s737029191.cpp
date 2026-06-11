#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int N, M, X; cin >> N >> M >> X;
  vi cost(N);
  vvi al(N, vi(M)); 
  rep(i,N){
    int c; cin >> cost[i];
    rep(j,M){
      int d; cin >> d;
      al[i][j]=d;
    }
  }
  int ans =1e9;
  bool can = false;
  for (int bit=0; bit<(1<<N); bit++){
    int pr = 0;
    vi alt(M,0); 
    for (int i=0; i<N; i++){
      if(bit & (1<<i)) {
        pr += cost[i];
        rep(j,M) alt[j] += al[i][j];
      }
    }
    int countM = 0;
    rep(i,M){ if (alt[i] >= X) countM++;}
    if(countM == M){
      ans = min(ans, pr);
      can = true;
    }
  }
  if(can) cout << ans << endl;
  else cout << -1 << endl;
}
  