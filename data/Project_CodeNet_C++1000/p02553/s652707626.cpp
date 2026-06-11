#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t A, B, C, D;
  cin >> A >> B >> C >> D;
  int64_t ans;
  ans = max(A*C, max(A*D, max(B*C, B*D)));
  cout << ans << endl;
}
