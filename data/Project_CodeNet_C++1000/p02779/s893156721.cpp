#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n;
  cin >> n;

  set<int> st;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    st.insert(a);
  }
  if ((int)st.size() == n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
