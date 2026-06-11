#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      for (int l = 0; ; l++) {
        if ((i ^ j) & 1 << l) {
          if (j) cout << ' ';
          cout << l+1;
          break;
        }
      }
    }
    cout << endl;
  }
}
