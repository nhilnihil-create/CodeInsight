#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int lower = n / 1.08;
  int upper = (n + 1) /1.08;
  ++upper;
  bool flag = false;
  int x = lower;
  for (; x <= upper; ++x) {
    int v = (int)(x * 1.08);
    if (v == n) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << x << '\n';
  else
    cout << ":(\n";
  return 0;
}
// (int)(x * 1.08) = n
// x * 1.08 = n + 0....
// x = (n + 0....)/1.08 = 
