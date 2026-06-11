#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int mod = 1000000007;

int main() {
  ll n, d, a;
  cin >> n >> d >> a;
  vector<P> p;
  rep(i, n) {
    ll x, h;
    cin >> x >> h;
    p.push_back(P(x, h));
  }
  sort(p.begin(), p.end());

  ll ans = 0;
  ll total = 0;
  queue<P> q;

  rep(i, n) {
    ll x = p[i].first;
    ll h = p[i].second;
    while (!q.empty() && q.front().first < x) {
      total -= q.front().second;
      q.pop();
    }
    h -= total;
    if (h > 0) {
      int num = (h + a - 1) / a;
      ans += num;
      ll limit = x + 2 * d;
      total += num * a;
      q.emplace(limit, num * a);
    }
  }

  cout << ans << endl;
}