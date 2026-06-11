#include <iostream>
using namespace std;

bool isprime[123457 * 2];

void eratos(void) {
  for (int i = 0; i < 123457 * 2; i++)
    isprime[i] = true;
  isprime[0] = isprime[1] = false;
  for (int i = 2; i * i < 123457 * 2; i++) {
    for (int j = i + i; j < 123457 * 2; j += i) {
      isprime[j] = false;
    }
  }
}

int main() {
  eratos();
  while (true) {
    int n;
    cin >> n;
    if (n == 0) return 0;

    int count = 0;
    for (int i = n + 1; i <= 2 * n; i++)
      if (isprime[i]) count++;

    cout << count << endl;
  }
}