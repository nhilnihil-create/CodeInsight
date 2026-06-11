#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main() {
  size_t n;
  cin >> n;
  set<int> st;
  rep(i,n) {
    int x;
    cin >> x;
    st.insert(x);
  }
  if (st.size() == n) cout << "YES" << endl;
  else cout << "NO" << endl;
}
