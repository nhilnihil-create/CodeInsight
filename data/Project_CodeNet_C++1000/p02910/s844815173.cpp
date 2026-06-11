#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
  string S;
  cin >> S;
  bool flag = true;
  for (int i = 1; i < S.size(); i += 2) {
    if (S[i] != 'L' && S[i] != 'U' && S[i] != 'D') flag = false;
  }
  for (int i = 0; i < S.size(); i += 2) {
    if (S[i] != 'R' && S[i] != 'U' && S[i] != 'D') flag = false;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
