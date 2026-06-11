#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int n = pow(2, t);
  vector<int> s(n);
  rep(i, n) cin >> s[i];
  sort(s.begin(), s.end());
  vector<int> slime = {s.back()};
  multiset<int> st;
  rep(i, n-1) st.insert(s[i]);
  rep(i, t) {
    int sz = slime.size();
    rep(j, sz) {
      auto it = st.lower_bound(slime[j]);
      if (it == st.begin()) {
        cout << "No" << endl;
        return 0;
      }
      it--;
      slime.push_back(*it);
      st.erase(it);
    }
    sort(slime.rbegin(), slime.rend());
  }
  cout << "Yes" << endl;
  return 0;
}