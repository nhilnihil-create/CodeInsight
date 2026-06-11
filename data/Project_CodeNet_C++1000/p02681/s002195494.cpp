#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  string s,t;
  cin >> s >> t;
  int ns = s.length();
  int nt = t.length();
  bool good = nt == ns+1;
  if (good) t.pop_back();
  if (good && t == s) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
