#include <iostream>

using namespace std;

int r;

void rec(int n, int s, int x) {
  if (!n && !s) {
    r++;
    return;
  }
  for (; x >= 0; x--)
    if (x <= s)
      rec(n-1, s-x, x-1);
}

int main() {
  for (;;) {
    int n, s;
    cin >> n >> s;
    if (!n && !s) return 0;
    r = 0;
    rec(n, s, 9);
    cout << r << endl;
  }
  return 0;
}