#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int A;
  set<int> st;
  rep(i, N) {
    cin >> A;
    st.insert(A);
  }

  if (N == st.size())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}