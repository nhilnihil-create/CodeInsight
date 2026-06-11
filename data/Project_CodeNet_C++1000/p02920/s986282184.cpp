#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v) {
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    cout << v[i] << " \n"[i == sz - 1];
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> s(1 << n);
  for (int i = 0; i < (1 << n); i++) cin >> s[i];
  sort(s.rbegin(), s.rend());
  if (s[0] == s[1]) {
    cout << "No" << endl;
    return 0;
  }
  multiset<int> st;
  for (int i = 1; i < (1 << n); i++) st.insert(s[i]);
  multiset<int> cur = {s[0]};
  for (int i = 0; i < n; i++) {
    vector<int> tmp;
    for (auto v : cur) {
      auto itr = st.lower_bound(v);
      if (itr == st.begin()) {
        cout << "No" << endl;
        return 0;
      }
      itr--;
      tmp.push_back(*itr);
      st.erase(itr);
    }
    //cout << tmp.size() << endl;
    for (auto v : tmp) cur.insert(v);
  }
  cout << "Yes" << endl;
}
