#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t A, B, N;
  cin >> A >> B >> N;
  int64_t M = min(B - 1, N);
  int64_t ans = (floor((A * M) / B) - A * floor(M / B));
  cout << ans << endl;
}