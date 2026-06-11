#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  bool can = true;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 0) {
      if (tmp % 3 != 0 && tmp % 5 != 0) {
        can = false;
        break;
      }
    }
  }
  if (can) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}
