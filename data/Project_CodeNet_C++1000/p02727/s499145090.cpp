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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll X,Y,A,B,C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A), q(B), r(C);
  vector<ll> mix;
  repr(i, A, 0) cin >> p[i];
  repr(i, B, 0) cin >> q[i];
  repr(i, C, 0) cin >> r[i];

  sortd(p); sortd(q); sortd(r);
  
  for (int i = 0; i < X; ++i) mix.push_back(p[i]);
  for (int i = 0; i < Y; ++i) mix.push_back(q[i]);
  sorti(mix);
  for (int i = 0; i < min<int>(mix.size(), C); ++i) {
    if (mix[i] < r[i]) {
      mix[i] = r[i];
    } else {
      break;
    }
  }

  ll ans = 0;
  for (auto itr : mix) {
    ans += itr;
  }

  cout << ans << endl;
}
