#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, ans = 1;
  cin >> N >> K;
  
  do {
    if (N < K) break;
    N = N/K;
    ans += 1;
  } while (N >= K);
  
  cout << ans << endl;
}