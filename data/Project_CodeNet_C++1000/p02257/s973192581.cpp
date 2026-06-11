#include <iostream>
#include <vector>
#include <math.h>
#define eol '\n'
using namespace std;

bool is_prime_number(int num) {
  if (num < 2) {
    return false;
  } else if (num == 2) {
    return true;
  } else if (num % 2 == 0) {
    return false;
  }
  
  for (int i = 3; i <= sqrt(num); i+=2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, num, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (is_prime_number(num)) {
      cnt++;
    }
  }

  cout << cnt << eol;
  
  return 0;
}