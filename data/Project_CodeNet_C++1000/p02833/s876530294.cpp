#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  int N; cin >> N;
  
  if(N%2 == 1) cout << 0 << endl;
  else {
    N /= 2;
    int five = 0;
    while(N > 0) {
      N /= 5;
      five += N;
    }
    cout << five << endl;
  }
    
  
}