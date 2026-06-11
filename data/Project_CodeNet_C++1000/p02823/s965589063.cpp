#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,A,B;
  cin >> N >> A >> B;
  const int64_t diff= B-A;

  int64_t ans= (diff%2==0) ? diff/2
                           : diff/2+ min(A-1, N-B)+ 1;

  cout << ans << endl;
}