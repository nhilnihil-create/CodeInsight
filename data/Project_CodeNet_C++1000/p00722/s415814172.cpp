#include <iostream>
#include <cmath>
using namespace std;

int a, d, n;

bool isPrime(int x) {
  int l = (int)sqrt(x);
  if(x == 1) return false;
  if(x == 2) return true;
  if(x % 2 == 0) return false;
  for(int i = 3; i <= l; i += 2) {
    if(x % i == 0) return false;
  }
  return true;
}

int solve() {
  int cnt = 0;
  int tmp = a;
  for(int i = 0; ; i++) {
    if(isPrime(tmp)) {
      cnt++;
      if(cnt == n) return tmp;
    }
    tmp += d;
  }
}

main() {
  while(1) {
    cin >> a >> d >> n;
    if(a == 0 && d == 0 && n == 0) break;
    
    cout << solve() << endl;
  }
}