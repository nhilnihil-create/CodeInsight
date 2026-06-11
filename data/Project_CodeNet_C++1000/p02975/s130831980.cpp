#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i];
  }

  int ex_sum = accumulate(va.begin(), va.end(), 0, [](int a, int b) { return a ^ b; });
  if (ex_sum == 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
