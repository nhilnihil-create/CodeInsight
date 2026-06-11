#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  int a, b, c; cin >> a >> b >> c;
  
  if(c-a-b <= 0) cout << "No" << endl;
  else if(4*a*b < (c-a-b)*(c-a-b)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
