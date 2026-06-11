#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 100100100;
vector<int> to[100005];

int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> H(N);
  rep(i,N) cin >> H[i];
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  int ans = 0;
  rep(i,N){
    bool can = true;
    int l = to[i].size();
    rep(j,l){
      if(H[i] <= H[to[i][j]]){
        can = false;
        break;
      }
    }
    if(can) ans++;
  }
  cout << ans << endl;
  return 0;
}