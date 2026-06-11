#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1000000000;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  set<int> st;
  st.insert(a);
  st.insert(b);
  st.insert(c);
  if (st.size() == 2) std::cout << "Yes" << endl;
  else std::cout << "No" << endl;
}
