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

template <class T>
set<T> divisor(const T n) {
  set<T> st;
  for (T i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      st.insert(i);
      st.insert(n / i);
    }
  }

  return st;
}

int main() {
  ll N;
  cin >> N;

  set<ll> ans;

  for (auto num : divisor(N-1)) {
    if (num == 1) continue;
    ans.insert(num);
  }

  for (auto num : divisor(N)) {
    if (num == 1) continue;
    ll cpy = N;
    while (cpy > 0) {
      cpy /= num;
      auto m = cpy % num;
      if (m > 0) {
        if (m == 1) ans.insert(num);
        break;
      }
    }
  }

  cout << ans.size() << endl;
}