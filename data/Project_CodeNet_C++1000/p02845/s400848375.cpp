#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MOD = 1e9 + 7;

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  multiset<int> st;

  int ans = 1;
  for (int i = 0; i < N; i++) {
    if (A[i] != 0 && st.count(A[i] - 1) == 0) {
      cout << 0 << endl;
      return 0;
    }

    if (A[i] == 0) {
      ans *= (3 - st.count(0));
      ans %= MOD;
    } else {
      ans *= (st.count(A[i] - 1) - st.count(A[i]));
      ans %= MOD;
    }

    st.insert(A[i]);

    if (st.count(A[i]) > 3) {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;
}