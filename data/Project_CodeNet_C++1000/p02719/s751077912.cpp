#include<bits/stdc++.h>
using namespace std;
int main() {
  long long n, k; cin >> n >> k;
  if(n > k) {
    while(n * 2 >= k) {
      if(n > k) {
        n %= k;
      }
      else {
        n = k % n;
      }
    }
    cout << n << endl;
  }
  else {
    if(n * 2 >= k) {
      cout << k - n << endl;
    }
    else {
      cout << n << endl;
    }
  }
}