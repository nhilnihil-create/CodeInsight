#include <bits/stdc++.h>
using namespace std;


bool isPrime(int number) {
    for(int i = 2; i < number; i++) {
      if(number % i == 0) return false;
    }
  return true;
}

int main() {
  int num; cin >> num;
  
  int ans = num;
  while(!isPrime(ans)) {
    ans++;
  }
  
  cout << ans << endl;
  
  return 0; 
}
