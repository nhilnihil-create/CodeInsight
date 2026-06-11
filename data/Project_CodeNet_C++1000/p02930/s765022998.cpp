#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if(j != i + 1) cout << " ";
      for(int k = 0; k < 60; ++k)
        if((i >> k & 1) != (j >> k & 1)) {
          cout << k + 1;
          break;
        }
    }
    cout << endl;
  }
  return 0;
}
