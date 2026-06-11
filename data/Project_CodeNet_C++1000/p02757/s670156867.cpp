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

  ll N,P;
  ll ans = 0;
  cin >> N >> P;
  string S;
  cin >> S;

  if (P == 2) {
    for (int i = 1; i <= N; ++i) {
      int num = S[i-1] - '0';
      if (num % 2 == 0) {
        ans += i;
      }
    }
  } else if (P == 5) {
    for (int i = 1; i <= N; ++i) {
      int num = S[i-1] - '0';
      if (num == 0 || num == 5) {
        ans += i;
      }
    }
  } else {
    vector<ll> val(P+1, 0);
    val[0] ++;
    ll cur = 0;
    ll fac = 1;
    reverse(S.begin(), S.end());
    for (int i = 0; i < N; ++i) {
      ll num = S[i] - '0';
      cur = (cur + num * fac) % P;
      fac = (fac * 10) % P;
      val[cur] += 1;
    }
    for (auto itr : val) {
      ans += itr * (itr - 1) / 2;
    }
  }
  cout << ans << endl;
}
