#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  ll sum;
  cin >> n;
  
  sum = 0;
  for (int i=1; i<=n; i++) {
    if (i%3 != 0) {
      sum += i;
    }
    if (i%3 != 0 && i%5 == 0) {
      sum -= i;
    }
  }
  cout << sum << endl;
}