#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K, R;
  cin >> N >> K;
  R = N % K;
  if (R == 0)
    cout << 0 << endl;
  else 
    cout << min(R, abs(R-K)) << endl;
}
