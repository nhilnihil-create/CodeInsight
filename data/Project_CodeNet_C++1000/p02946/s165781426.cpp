#include <iostream>

using namespace std;

int main() {
  int K, X;
  cin >> K >> X;
  const char* sep = "";
  for (int i = X - K + 1; i < X + K; ++i) {
    cout << sep << i;
    sep = " ";
  }
  cout << endl;
  return 0;
}
