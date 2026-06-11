#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  map<int, int> cnts;
  for (int i = 0; i < n; i++) {
    cin >> va[i];
    cnts[va[i]]++;
  }

  if (n % 3 != 0) {
    cout << (cnts[0] == n ? "Yes" : "No") << '\n';
    return 0;
  }

  bool ans;
  switch (cnts.size()) {
    case 1: {
      ans = cnts[0] == n;
      break;
    }
    case 2: {
      ans = cnts[0] == n / 3;
      break;
    }
    case 3: {
      int xor_all = accumulate(cnts.begin(), cnts.end(), 0,
                               [](int a, auto b) { return a ^ b.first; });
      ans = xor_all == 0 && all_of(cnts.begin(), cnts.end(),
                                   [&](auto p) { return p.second == n / 3; });
      break;
    }
    default: { ans = false; }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
