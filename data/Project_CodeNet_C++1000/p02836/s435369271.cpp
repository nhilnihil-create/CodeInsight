#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string S;
  cin >> S;
  ll co = 0;
  rep(i, S.size() / 2) {
    if(S.at(i) != S.at(S.size() - i - 1)) {
      co++;
    }
  }
  cout << co << endl;
}