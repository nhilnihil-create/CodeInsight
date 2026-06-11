#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int64_t x;
  cin >> x;
  int64_t a, b = -120;
  for(int64_t a = -120; a < 120; a++) {
    for(int64_t b = -120; b < 120; b++) {
      if(pow(a, 5) - pow(b, 5) == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
}

