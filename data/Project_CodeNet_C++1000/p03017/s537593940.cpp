#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,A,B,C,D;
  cin >> N >> A >> B >> C >> D;
  A--;
  B--;
  C--;
  D--;
  string S;
  cin >> S;
  bool ans = true;
  if (C < D) {
    for (int i = A+1; i <= D-2; i++) {
      if (S[i] == '#' && S[i+1] == '#') {
        ans = false;
      }
    }
  } else {
    for (int i = A+1; i <= C-2; i++) {
      if (S[i] == '#' && S[i+1] == '#') {
        ans = false;
      }
    }
    bool ans2 = false;
    for (int i = B-1; i <= D-1; i++) {
      if (i + 2 < N) {
        if ((S[i] == '.' && S[i+1] == '.') && S[i+2] == '.') {
          ans2 = true;
        }
      } 
    }
    if (!ans2) ans = false;
  } 
  
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}