#include <iostream>

using namespace std;

int lunlun(long n) {
  long a = n % 10, b, diff;
  n /= 10;
  for(; n > 0; n /= 10) {
    b = n % 10;
    diff = a - b;
    if(diff > 1 || diff < -1) {
      return false;
    }
    a = b;
  }

  return true;
}

long next(long n) {
  if(n < 10) {
    return n + 1;
  }

  long a, b;
  a = n % 10 + 1;
  //cout << "a == " << a << endl;
  n /= 10;
  int i;
  for(i = 0; n > 0; i++) {
    b = n % 10;
    if(a == 10 || a - b == 2) {
      a = b + 1;
    } else {
      break;
    }
    n /= 10;
  }
  //cout << "n == " << n << endl;
  //cout << "i == " << i << endl;
  //cout << "a == " << a << endl;


  n *= 10;
  n += a;
  a %= 10;
  for(; i > 0; i--) {
    if(a > 0) {
      a -= 1;
    }

    n = n * 10 + a;
  }

  return n;
}

int main2() {
  cout << next(123) << endl;
}

int main() {
  int K;
  cin >> K;

  long n = 0;
  for(int i = 0; i < K; i++) {
    n = next(n);
  }

  cout << n;

  return 0;
}
