#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i++) {

    int k = 0, cp = i;

    while (cp >= 10) {
      cp /= 10;
      k++;
    }

    if (k % 2 == 0) ans++;
  }
  
  cout << ans << endl;
}