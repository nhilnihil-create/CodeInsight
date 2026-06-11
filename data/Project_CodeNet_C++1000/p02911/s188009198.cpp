#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> v(N, K - Q);
  rep(i, Q) {
    int a;
    cin >> a;
    a--;
    v.at(a)++;
  }
  rep(i, N) {
    if (v.at(i) > 0) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  return 0;
}
