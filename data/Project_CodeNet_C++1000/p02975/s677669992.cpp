#include <iostream>
using namespace std;
int main() {
  int n, a[100000], sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum ^= a[i];
  }
  if (sum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}