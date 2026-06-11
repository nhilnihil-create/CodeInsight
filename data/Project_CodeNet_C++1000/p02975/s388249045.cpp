#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &va) {
  map<int, int> cnts;
  for (auto &a : va) {
    cnts[a]++;
  }

  if (va.size() % 3 != 0) {
    return cnts[0] == va.size();
  }

  bool ans;
  switch (cnts.size()) {
    case 1: {
      ans = cnts[0] == va.size();
      break;
    }
    case 2: {
      ans = cnts[0] == va.size() / 3;
      break;
    }
    case 3: {
      int xor_all = accumulate(cnts.begin(), cnts.end(), 0,
                               [](int a, auto b) { return a ^ b.first; });
      ans = xor_all == 0 && all_of(cnts.begin(), cnts.end(), [&](auto p) {
              return p.second == va.size() / 3;
            });
      break;
    }
    default: {
      ans = false;
      break;
    }
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i];
  }

  cout << (solve(va) ? "Yes" : "No") << '\n';
  return 0;
}
