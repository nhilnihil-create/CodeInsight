 #include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n;
  cin >> n;

  int m = n;
  set<int> st;
  for (int t = 0; t < 2; t++) {
    for (int i = 2; i * i <= n; i++) {
      if(n % i == 0) {
        st.insert(i);
        st.insert(n/i);
      }
    }
    st.insert(n);
    n--;
  }

  st.erase(1);

  int answer = 0;
  for (auto & k : st) {
    int x = m;
    while (true) {
      if(x % k == 0) x /= k;
      else if(x % k == 1) {
        answer++;
        break;
      } else {
        break;
      }
    }
  }
  cout << answer << '\n';
}
