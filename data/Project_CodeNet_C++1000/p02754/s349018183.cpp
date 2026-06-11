#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t N, A, B;
  cin >> N >> A >> B;
  int64_t i = (A + B) * (N / (A + B));
  int64_t ans = A * (N / (A + B));
  if ((i + A) < N) {
    ans += A;
  }
  else {
    ans += (N - i);
  }
  cout << ans << endl; 
}