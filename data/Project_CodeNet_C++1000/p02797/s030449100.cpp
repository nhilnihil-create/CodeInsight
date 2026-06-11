#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG



signed main() {
  int N, K, S; cin >> N >> K >> S;
  
  rep(i, K) cout << S << " ";
  rep(i, N-K) {
    if(S != 1000000000) cout << 1000000000 << " ";
    else cout << 1 << " ";
  }
  cout << endl;
  

  
}
