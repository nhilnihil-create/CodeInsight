#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;
const ll MAXV = 1e18;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  rep(i, n) {
    if (MAXV / ans < a[i]) {
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }

  cout << ans << endl;
}