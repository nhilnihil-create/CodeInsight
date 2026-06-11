#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  multiset<int> st;
  rep(i, n) st.insert(-a[i]);

  rep(i, m) {
    auto itr = st.begin();
    int x = (-*itr) / 2;
    st.erase(itr);
    st.insert(-x);
  }

  ll ans = 0;
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    ans -= *itr;
  }
  cout << ans << endl;
  return 0;
}