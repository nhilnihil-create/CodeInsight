#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int K;
  string S;
  cin >> K >> S;
  if (S.size() <= K) cout << S << endl;
  else {
    rep(i,K) {
      cout << S.at(i);
    }
    cout << "..." << endl;
  }      
}