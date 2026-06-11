#include <iostream>
using namespace std;

int prime[2 * 123460];
int main() {
  for (int i = 0; i < 2 * 123457; ++i) {
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  for (int i = 2; i < 2 * 123457; ++i) {
    if (!prime[i]) continue;
    for (int j = i + i; j < 2 * 123457; j += i) {
      prime[j] = 0;
    }
  }
  for (int i = 0; i < 2 * 123456; ++i) {
    prime[i + 1] += prime[i];
  }

  int n;
  while (cin >> n, n) {
    cout << prime[2 * n] - prime[n] << endl;
  }
}