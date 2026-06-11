#include <iostream>

using namespace std;

int main() {
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;
  const char* result = "win";
  if (22 <= A1 + A2 + A3) {
    result = "bust";
  }
  cout << result << endl;
  return 0;
}
