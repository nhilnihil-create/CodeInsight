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

  int N, K;
  cin >> N >> K;
  vector<bool> v(N+1);
  for (int i = 0; i < K; ++i) {
    int d;
    cin >> d;
    for (int j = 0; j < d; ++j) {
      int a;
      cin >> a;
      v[a] = true;
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (!v[i]) ans += 1;
  }

  cout << ans << endl;
}
