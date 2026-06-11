#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N;
  string S;
  cin >> N >> S;
  ll A = S.size();
  if(A <= N) {
    cout << S << endl;
  }
  else {
    rep(i, N) {
      cout << S.at(i);
    }
    cout << "..." << endl;
  }
}