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
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> a(N);
  repr(i, N, 0) cin >> a[i];
  a[0] -= 1;
  for (int i = 1; i < N; ++i) {
    if (a[i] - 1 >= a[i-1]) a[i] -= 1;
  }
  vector<int> src(a.begin(), a.end());
  sorti(src);
  if (a == src) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}