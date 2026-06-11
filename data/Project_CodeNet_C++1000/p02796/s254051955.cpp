#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n), l(n);
  repr(i, n, 0) cin >> x[i] >> l[i];
  using pl = pair<ll, ll>;
  vector<pl> rng;
  rng.reserve(n);
  for (int i = 0; i < n; ++i) {
    pl p {x[i] + l[i], x[i] - l[i]};
    rng.push_back(p);
  }
  sorti(rng);
  ll cnt = 0;
  pl now = rng.front();
  for (int i = 1; i < n; ++i) {
    pl next = rng[i];
    if (next.second >= now.first) {
      now = next;
    } else {
      cnt ++;
    }
  }

  cout << n - cnt << endl;
}