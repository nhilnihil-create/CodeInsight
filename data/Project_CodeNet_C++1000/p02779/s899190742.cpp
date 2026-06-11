#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  set<int> st;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    st.insert(x);
  }
  int l = 0;
  for(int i : st) l++;
  cout << (l == n ? "YES" : "NO") << endl;
  return 0;
}