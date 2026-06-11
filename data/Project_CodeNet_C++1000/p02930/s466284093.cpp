#include <iostream>

using namespace std;

int n;

int main() {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int group = 32 - __builtin_clz(i ^ j);
      cout << group << " ";
    }
    cout << endl;
  }

  return 0;
}
