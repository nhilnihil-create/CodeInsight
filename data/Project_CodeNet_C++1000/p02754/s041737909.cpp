#include <iostream>
using namespace std;

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  long long res = 0;
  res += (N / (A+B)) * A + min(N % (A+B), A);
  cout << res << endl;
}