#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K, d, A;
  cin >> N >> K;

  set<int> su;
  rep(i, K) {
    cin >> d;
    rep(j, d) {
      cin >> A;
      su.insert(A);
    }
  }
  cout << N - su.size() << endl;
  return 0;
}