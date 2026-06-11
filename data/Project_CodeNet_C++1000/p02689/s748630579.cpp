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

  int N,M;
  cin >> N >> M;
  vector<int> H(N);
  repr(i, N, 0) {
    cin >> H[i];
  }

  vector<vector<int>> G(N+1);
  for (int i = 0; i < M; ++i) {
    int a,b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int h = H[i-1];
    bool flag = true;
    for (auto& t : G[i]) {
      if (H[t-1] >= h) {
        flag = false;
      }
    }

    if (flag) ans += 1;
  }

  cout << ans << endl;
}
