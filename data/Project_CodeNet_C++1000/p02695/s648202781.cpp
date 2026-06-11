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

vector<int> a,b,c,d;
int N,M,Q;
ll ans = 0;

void dfs(int now, int cnt, vector<int> num) {
  if (cnt == N) {
    ll temp = 0;
    for (int i = 0; i <= Q; ++i) {
      if (num[b[i]] - num[a[i]] == c[i]) temp += d[i];
    }

    if (temp > ans) ans = temp;

    return;
  }

  for (int i = now; i <= M; ++i) {
    auto n = num;
    n.push_back(i);
    dfs(i, cnt+1, n);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M >> Q;

  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }
  
  dfs(1, 0, vector<int>());

  cout << ans << endl;
}
