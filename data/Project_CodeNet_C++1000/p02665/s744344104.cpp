#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  rep(i, n + 1) cin >> a[i];

  vector<ll> mins(n + 1), maxes(n + 1);

  mins[n] = a[n];
  maxes[n] = a[n];
  for (int i = n - 1; i >= 0; --i) {
    mins[i] = (mins[i + 1] + 1) / 2 + a[i];
    maxes[i] = maxes[i + 1] + a[i];
  }

  if (mins[0] > 1) {
    puts("-1");
    return 0;
  }

  ll ans = 1;
  ll pre = 1;
  for (int i = 1; i <= n; ++i) {
    ll minv = min(pre * 2, maxes[i]);
    ans += minv;
    pre = minv;
    pre -= a[i];
  }

  cout << ans << endl;

}