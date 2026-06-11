#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  if (B == 1) {
    cout << 0 << endl;
    return 0;
  }
  int cnt = 1;
  B -= A;

  while (B > 0) {
    B -= A - 1;
    ++cnt;
  }
  cout << cnt << endl;
}
