#include <iostream>
using namespace std;

int main() {
  long N;
  long K;
  cin >> N;
  cin >> K;
  long sum = 0;
  for (long p = K; p <= N+1; p++) {
    sum += (long)p*N-p*(p-1)+1;
  }
  long ans = sum % (1000000007);
  cout << ans << endl;;
}

