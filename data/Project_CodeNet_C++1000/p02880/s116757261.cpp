#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool ok = false;
  for (int i = 1; i < 10; i++) {
    int j = n/i;
    if (j <= 9 && i*j == n) {
      ok = true;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}