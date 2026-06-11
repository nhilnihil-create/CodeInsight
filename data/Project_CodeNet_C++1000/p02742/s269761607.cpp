#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long h, w;
  cin >> h >> w;

  long long result;
  if (h == 1 || w == 1) {
    result = 1;
  } else if (h % 2 == 1 && w % 2 == 1) {
    result = h * w / 2 + 1;
  } else {
    result = h * w / 2;
  }
  cout << result << endl;
  return 0;
}