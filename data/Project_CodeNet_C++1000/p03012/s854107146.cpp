#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> w(n);
  rep(i, 0, n) cin >> w[i];

  int l = 0, r = accumulate(w.begin(), w.end(), 0);
  int ans = 1e9;
  rep(i,0,n){
    l+=w[i];
    r-=w[i];
    chmin(ans, abs(l-r));
  }

  cout<<ans<<endl;
}
