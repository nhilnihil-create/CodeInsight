#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

template <class T>
T inf = numeric_limits<T>::max();

// 方針
// 累積和を取る
// ex) 18171
// s[4] 1
// s[3] 71
// s[2] 171
// s[1] 8171
// s[0] 18171
// mod 2019 = 0の区間(i, j), i < j は, (s[i] - s[j]) mod 2019 = 0
// つまり, s[i] mod 2019 == s[j] mod 2019

ll calc(ll t) {
  return t * (t-1) / 2;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  
  reverse(s.begin(), s.end());
  vector<ll> val(2019, 0);
  val[0] += 1;
  ll fac = 1;
  ll cur = 0;
  for (auto itr : s) {
    ll num = itr - '0';
    cur = (cur + num * fac) % 2019;
    val[cur] += 1;
    fac = (fac * 10) % 2019;
  }

  ll ans = 0;
  for (int i = 0; i < 2019; ++i) {
    ans += calc(val[i]);
  }
  
  cout << ans << endl;
}
