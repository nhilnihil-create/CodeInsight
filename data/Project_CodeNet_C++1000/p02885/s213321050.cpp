#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int result = A - (2 * B) >= 0 ? A - (2 * B) : 0;
  cout << result << endl;
}