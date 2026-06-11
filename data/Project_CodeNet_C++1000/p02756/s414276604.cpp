#include <bits/stdc++.h>
using namespace std;
 
int main () {
  string S;
  cin >> S;
  deque<char> M;
  int S2 = S.size();
  for (int i = 0; i < S2; i++) {
    M.push_back(S.at(i));
  }
  int Q;
  cin >> Q;
  bool ok = true;
  for (int i = 0; i < Q; i++) {
    int T;
    cin >> T;
    if (T == 1) {
      if (ok) {
        ok = false;
      }
      else {
        ok = true;
      }
    }
    else {
      int F;
      cin >> F;
      char C;
      cin >> C;
      if (F == 1 && ok) {
        M.push_front(C);
      }
      if (F == 1 && ok == false) {
        M.push_back(C);
      }
      if (F == 2 && ok) {
        M.push_back(C);
      }
      if (F == 2 && ok == false) {
        M.push_front(C);
      }
    }
  }
  if (ok == false) {
    reverse(M.begin(), M.end());
  }
  int M2 = M.size();
  for (int i = 0; i < M2; i++) {
    cout << M.at(i);
  }
  cout << endl;
}