#include<bits/stdc++.h>
using namespace std;
int main() {
  int x; cin >> x;
  bool found = 0;
  while(!found) {
    bool primeornot = 1;
    for(int i = 2; i * i <= x; i++) {
      if(x % i == 0) {
        primeornot = 0;
      }
    }
    if(primeornot) {
      found = 1;
    }
    x++;
  }
  cout << x - 1 << endl;
}