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

  ll K, N;
  cin >> K >> N;
  vector<ll> A(N+2);
  repr(i, N+1, 1) {
    cin >> A[i];
  }

  A[0] = A[N] - K;
  A[N+1] = A[1] + K;

  ll ans = inf<int>;
  for (int i = 1; i < N+1; ++i) {
    chmin(ans, K - max(abs(A[i] - A[i-1]), abs(A[i+1] - A[i])));
  }

  cout << ans << endl;
}
