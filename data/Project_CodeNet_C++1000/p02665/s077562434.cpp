#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep(i, n + 1) cin >> a[i];

  vector<ll> l(n + 1), r(n + 2); // 深さiにおける最小ノード数lと、最大ノード数r
  l[n] = r[n] = a[n];
  for (int i = n - 1; i >= 0; --i) {
    l[i] = (l[i + 1] + 1) / 2 + a[i];
    r[i] = a[i] + r[i + 1];
  }

  if (l[0] > 1) {
    cout << -1 << endl;
    return 0;
  }

  ll cur = 1;
  ll ans = 0;
  rep(i, n + 1) {
    ans += cur;
    cur -= a[i];
    cur = min(cur*2, r[i + 1]);
  }
  cout << ans << endl;
}