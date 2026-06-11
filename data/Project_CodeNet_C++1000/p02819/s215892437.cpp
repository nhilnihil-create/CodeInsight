#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, ans;
  cin >> X;
  vector<int> V(1000001, 1);
  for (int i=2; i<=1000000; i++) {
    if (V[i]) {
      if (i>=X) {
        ans = i;
        break;
      }
      else {
        for (int j=i; j<=1000000; j+=i) {
          V[j]=0;
        }
      }
    }
  }
  cout << ans << endl;
}