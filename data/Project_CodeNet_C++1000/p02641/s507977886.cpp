/**
 *    author:  morato
 *    created: 29.08.2020 17:19:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, n;
  cin >> x >> n;
  set<int> st;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    st.insert(k);
  }
  int l = x, r = x;
  while (true) {
    if (!st.count(l)) {
      cout << l << '\n';
      return 0;
    }
    if (!st.count(r)) {
      cout << r << '\n';
      return 0;
    }
    l--, r++;
  }
  return 0;
}