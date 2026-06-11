#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
  for(int i = 2; i*i <= x; ++i) {
    if(x % i == 0) return false; 
  }
  return true;
}

int main() {
  for(int n; cin >> n && n;) {
    int res = 0;
    for(int x = n+1; x <= 2*n; ++x) {
      if(isPrime(x)) ++res;
    }
    cout << res << endl;
  }
  return 0;
}