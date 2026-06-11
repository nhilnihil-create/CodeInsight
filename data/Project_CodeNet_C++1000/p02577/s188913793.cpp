#include <bits/stdc++.h>

using namespace std;

void test_case() {
  string s;
  cin >> s;

  int q = 0;
  for (int i = 0; i < s.size(); i++) {
    q += s[i] - '0';
  }

  if (q % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    test_case();
  }

  return 0;
}

