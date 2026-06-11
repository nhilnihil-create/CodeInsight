#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t h, w;
  cin >> h >> w;
  
  if (h == 1 || w == 1) {
    cout << 1 << endl;
  }
  else if ((h * w) % 2 == 0) {
    cout << h * w / 2 << endl;
  }
  else {
    cout << ((h - 1) * (w - 1) / 2) + ((h + w) / 2) << endl;
  }
}
