#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long A, B;
  cin >> A >> B;
  long long count = N / (A + B);
  N %= A + B;
  if (N <= A) cout << count * A + N << endl;
  else cout << count * A + A << endl;
}