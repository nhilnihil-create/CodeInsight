#include<bits/stdc++.h>
#include<atcoder/dsu>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n, q;
  cin >> n >> q;
  atcoder::dsu uf(n);

  rep(i, q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      uf.merge(u, v);
    } else {
      int ans = 0;
      if (uf.same(u, v)) ans = 1;
      cout << ans << endl;
    }
  }
}