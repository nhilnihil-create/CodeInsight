#include <bits/stdc++.h>

using namespace std;

void test_case() {
  int n, x, t;
  cin >> n >> x >> t;

  cout << t * ceil(1.0 * n / x) << endl;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << setprecision(20);
  
  int t = 1;
  // cin >> t;
  while (t--) {
    test_case();
  }

  return 0;
}
