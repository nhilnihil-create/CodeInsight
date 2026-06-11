#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  string S; cin >> S;
  int N = S.size() + 1;
  
  int ans = 0;
  int k = 0;
  char c = '0';
  int K = 0;
  rep(i, N-1) {
    if(S[i] == '<') {
      if(c == '>') {
        k = 0;
      }
      k++;
      //cout << k;
      ans += k;
      c = '<';
    }
    if(S[i] == '>') {
      if(c == '<') {
        K = k;
        k = -1;
      }
      k++;
      if(k == K) k++;
      //cout << k;
      ans += k;
      c = '>';
    }
  }
  cout << ans << endl;
  
  

}