#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  string N;
  cin >> N;

  int sum = 0;
  for (int i = 0; i < N.size(); i++) {
    sum += (int)(N[i] - '0');
  }

  if (sum % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}