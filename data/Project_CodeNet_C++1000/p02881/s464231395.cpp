#include <iostream>
 
using namespace std;
 
int main() {
  long long N;
  cin >> N;
  long long ans = N - 1;
  for (long long i = 1; i * i <= N; i++) {
    // N / i にあまりが発生したら i は N の約数ではない
    if (N % i) continue;
    long long j = N / i;
    ans = min(ans, i + j - 2);
  }
  cout << ans << endl;
}