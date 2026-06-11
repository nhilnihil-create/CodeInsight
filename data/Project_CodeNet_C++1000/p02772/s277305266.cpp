#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool res = true;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    if (A % 2 == 0) if (A % 3 != 0 && A % 5 != 0) res = false;
  }
  if (res) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}