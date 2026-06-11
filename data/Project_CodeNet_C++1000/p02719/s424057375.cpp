#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K, R;
  cin >> N >> K;
  R = N % K;
  cout << min(R, abs(R-K)) << endl;
}
