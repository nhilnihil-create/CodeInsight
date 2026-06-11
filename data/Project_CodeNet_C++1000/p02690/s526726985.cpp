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

template <class T>
T pow5(T x) {
  return x*x*x*x*x;
}

// 解けなかった悲しい
// 1 <= A**5 - B**5 <= 10**9 が条件
// X**5 - (X-1)**5 の値の変化を考える
// 例えば X = 200 とすると上式は 8080401001 となり、条件に反する。
// そのためこの問題におけるA, Bの上界の1つは200。下界も-200くらいまで調べればいい。

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll X;
  cin >> X;

  for (ll i = -200; i <= 200; ++i) {
    for (ll j = -200; j <= 200; ++j) {
      ll a = pow5(i);
      ll b = pow5(j);
      if (a - b == X) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}
