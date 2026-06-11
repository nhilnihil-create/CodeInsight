#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k, w, count;
  cin >> n >> k;
  
  w = k;
  count = 1;
  while (true) {
    if(n <= w-1) {
      cout << count << endl;
      break;
    }
    w *= k;
    count++;
  }
  return 0;
}