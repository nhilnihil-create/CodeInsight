#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int S[10];
char C[10];

int main(){
  int N, M;
  cin >> N >> M;
  rep(i, M){
    cin >> S[i];
    S[i]--;
    cin >> C[i];
  }

  int ans = 1000;

  rep(i, 10){
    rep(j, 10){
      rep(k, 10){
        bool check = true;
        string a = to_string(stoi(to_string(k) + to_string(j) + to_string(i)));
        rep(m, M){
          if (a[S[m]]!=C[m]) check = false;
        }
        if (check && to_string(stoi(a)).size()==N) ans = min(ans, stoi(a));
      }
    }
  }
  if (ans!=1000) cout << ans << endl;
  else cout << -1 << endl;
}
