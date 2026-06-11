#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N;
  cin >> N;
  vector<ll> vecA(N);
  vector<ll> vecB(N-1);
  ll sum = 0;
  ll X;
  rep(i, N) {
    cin >> vecA.at(i);
  }
  rep(i, N) {
    cin >> X;
    sum += X;
  }
  rep(i, N - 1) {
    cin >> vecB.at(i);
  }
  X = 1000;
  rep(i, N) {
    if(vecA.at(i) == X + 1) {
      sum += vecB.at(X-1);
    }
    X = vecA.at(i);
  }
  cout << sum << endl;
}