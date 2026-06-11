#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  set<string> st;

  string s;
  rep(i, N) {
    cin >> s;
    st.insert(s);
  }

  cout << st.size() << endl;
  return 0;
}