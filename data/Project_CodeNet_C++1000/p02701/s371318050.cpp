#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  set<string> st;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (st.count(s) == 0) {
      st.insert(s);
    }
  }

  cout << st.size() << endl;
  return 0;
}
