#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int64_t n,k;
  cin >> n >> k;
  
  int count = 0;
  
  while (n / k > 0) {
  n = n / k;
    count++;
  }
  
  cout << count + 1;
   
  
}