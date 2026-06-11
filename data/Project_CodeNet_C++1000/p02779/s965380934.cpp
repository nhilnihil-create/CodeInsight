#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  std::size_t n;
  cin >> n;
  set<int> st;
  rep(i, n) {
    int x;
    cin >> x;
    st.insert(x);
  }
  if (n == st.size()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
