#include "bits/stdc++.h"
using ll = long long;
using namespace std;

bool isPrime(int x) {
   for(int i = 2; i < x; i++) {
      if(x % i == 0)
      return false;
   }
   return true;
}
void solve() {
   int x;
   cin >> x;
   for(int i = x; ; i++) {
      if(isPrime(i)) {
         cout << i << endl;
         return;
      }
   }
}

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solve();
   } 
   return 0;
}
