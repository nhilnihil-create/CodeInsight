#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A;
  cin >> A;
  int X = A.size();
  int C = 0;
  if(X % 2 == 0) {
    for(int i = 0; i < X; i += 2) {
      if(A.at(i) == 'h' && A.at(i + 1) == 'i') {
        C++;
      }
    }
    if(C == X / 2) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    cout << "No" << endl;
  }
}
    