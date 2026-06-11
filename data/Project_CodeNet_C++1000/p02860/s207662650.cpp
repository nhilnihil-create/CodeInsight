#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N;
  string S;
  cin >> N >> S;
  int co = 0;
  if(N % 2 == 0) {
    rep(i, N/2) {
      if(S.at(i) == S.at(i + N/2)) {
        co++;
      }
    }
    if(co == N / 2) {
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