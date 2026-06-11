
#include <bits/stdc++.h>
using namespace std;

int yakusuu(long long a) {
  int count = 0;
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) {
      if (i == sqrt(a))
        count++;
      else
        count += 2;
    }
  }
  count++;
  return count;
}

int main() {
  long long n;
  cin >> n;
  long long count = 0;
  count += yakusuu(n - 1);
  if (n == 2) {
    cout << 1;
    return 0;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    long long a = n;
    while (a % i == 0) {
      a /= i;
      if (a == 1) {
        count++;
        break;
      }
    }
  }
  for (int i = 2; i <= sqrt(n); i++) {
    long long a = n;

    if (a % i != 0) continue;
    while (a % i == 0) {
      a /= i;
    }
    if (a == 1) continue;
    if ((a - 1) % i == 0) count++;
  }
  cout << count + 1;
  return 0;
}