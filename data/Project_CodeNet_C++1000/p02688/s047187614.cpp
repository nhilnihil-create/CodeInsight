#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N, K;
  cin >> N >> K;
  vector<int> vec(N);
  rep(i, N) {
    vec.at(i) = 0;
  }
  ll X, Y;
  rep(i, K) {
    cin >> X;
    rep(i, X) {
      cin >> Y;
      vec.at(Y - 1) = 1;
    }
  }
  int co = 0;
  rep(i, N) {
    if(vec.at(i) == 0) {
      co++;
    }
  }
  cout << co << endl;
}