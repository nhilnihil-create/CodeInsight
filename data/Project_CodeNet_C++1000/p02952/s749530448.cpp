#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int order = 1;
  int n = N;
  while(n >= 10) {
    n /= 10;
    order++;
  }
  int ans = 0;
  for(int i = order; i > 0; i--) {
    if(i % 2 == 0) {
      continue;
    }
    else if(i == order) {
      ans += N - pow(10, order - 1) + 1;
    }
    else {
      ans += pow(10, i) - pow(10, i - 1);
    }
  }
  cout << ans << endl;
}