#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if(n % 2 == 1) {
    for(int i = 0; i < m; i++) {
      cout << i + 1 << ' ' << n - (i + 1) << endl;
    }
  }
  else {
    int k = n / 2;
    cout << k << ' ' << n - 1 << endl;
    int count = 1;
    if((k - 1) % 2 == 1) {
      for(int i = 1; i <= (k - 2) / 2; i++) {
        if(count == m) break;
        cout << i << ' ' << k - i << endl;
        count++;
      }
      for(int j = 1; j <= (k - 2) / 2; j++) {
        if(count == m) break;
        cout << k + j << ' ' << n - 1 - j << endl;
        count++;
      }
    }
    else {
      for(int i = 1; i <= (k - 1) / 2; i++) {
        if(count == m) break;
        cout << i << ' ' << k - i << endl;
        count++;
      }
      for(int j = 1; j <= (k - 1) / 2; j++) {
        if(count == m) break;
        cout << k + j << ' ' << n - 1 - j << endl;
        count++;
      }
    }
  }
}