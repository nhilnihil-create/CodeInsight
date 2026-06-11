#include <iostream>
#include <vector>
using namespace std;
typedef size_t ll;
int main(void) {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll x = 0;
  for (size_t i = 0; i < N; i++) {
    cin >> A[i];
    x ^= A[i];
  }
  for (size_t i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << (x ^ A[i]);
  }
  cout << endl;
  return 0;
}