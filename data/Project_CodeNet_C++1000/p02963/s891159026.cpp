#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int S; cin >> S;
  
  int s = ceil(sqrt(S));
  
  int d = s*s - S;
  
  cout << "0 0 " << s << " 1 " << d << " " << s << endl;

}