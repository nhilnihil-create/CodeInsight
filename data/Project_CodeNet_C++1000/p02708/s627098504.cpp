#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;
  int64_t sum = 0;
  int p = 1000000007;
  
  for(int i = k; i <= n+1; i++){
    sum = (sum + (i*(n-i+1) +1) %p) %p;
  }
  
  cout << sum << endl;
  
  return 0;
  
}