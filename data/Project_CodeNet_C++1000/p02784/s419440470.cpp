#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int H, N;
  cin >> H >> N;

  int A;
  rep(i, N) {
    cin >> A;
    H -= A;
    if (H <= 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}