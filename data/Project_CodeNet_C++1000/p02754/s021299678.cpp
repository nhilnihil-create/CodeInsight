#include <iostream>

using namespace std;

int main() {
  long N, A, B;
  cin >> N;
  cin >> A;
  cin >> B;

  cout << N / (A + B) * A + min(N % (A + B), A);

  return 0;
}
