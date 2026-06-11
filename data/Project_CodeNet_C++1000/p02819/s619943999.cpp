#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
//素数判定関数は引用
bool is_prime(const unsigned n){
    switch(n) {
        case 0: // fall-through
        case 1: return false;
        case 2: return true;
    } // n > 2 が保証された
 
    if(n % 2 == 0) return false;
 
    // 上で i=2 相当は調べたので、i=3から奇数のみ調べる
    for(unsigned i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }
 
    return true;
}
 
int main() {
  // input
  int x; cin >> x;
 
  // compute 
  int ans = 0;
  
  for(int i = 0; i < 100000; i++){
    if(is_prime(x + i)){
        ans = x + i;
        break;
    }
  }
  
  // output  
  cout << ans << endl;
  
}