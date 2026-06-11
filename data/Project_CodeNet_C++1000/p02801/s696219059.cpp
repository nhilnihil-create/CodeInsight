#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  char A;
  cin >> A;
  string alp = "abcdefghijklmnopqrstuvwxyz";
  rep(i, alp.size()) {
    if(A == alp.at(i)) {
      cout << alp.at(i + 1) << endl;
    }
  }
}
