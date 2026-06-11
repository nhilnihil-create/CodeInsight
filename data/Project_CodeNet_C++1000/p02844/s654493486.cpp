#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// 全探索で解くべき問題だったが、数学的解法で解いてしまった
int main() {
  int n;
  cin >> n;
  string S;
  cin >> S;

  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    string si = to_string(i);
    if (i < 10) si = "00" + si;
    if (10 <= i && i < 100) si = "0" + si;
    
    for (int j = 0; j < n - 2; j++) {
      if(S[j] == si[0]) {
        for (int k = j + 1; k < n - 1; k++) {
          if (S[k] == si[1]) {
            for (int l = k + 1; l < n; l++) {
              if (S[l] == si[2]) {
                ans++;
                break;
              }
            }
            break;
          }
        }
        break;
      }
    }
  }
  
  cout << ans << endl;
  return 0;
}
