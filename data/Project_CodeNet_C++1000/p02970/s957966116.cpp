#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  
  int ans = 0;
  
  int num = 0;
  while (num < N) {
    ans ++;
    num += 2*D + 1;
  }

  cout << ans << endl;
}