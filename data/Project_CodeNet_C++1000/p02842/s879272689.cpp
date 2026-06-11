#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  bool flag = false;
  for (int i = 0; i <= 50000; ++i) {
    if (int(i * 1.08) != n)
      continue;
    cout << i << endl;
    flag = true;
    break;
  }
  if (flag == false)
    cout << ":(" << endl;
}
