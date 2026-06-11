#include <iostream>
using namespace std;
int main() {
  int n, q, S[10000], T, C, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> S[i];
  }
  cin >> q;
  C = 0;
  while (q--) {
    cin >> T;
    for (i = 0; i < n; i++) {
      if (S[i] == T) {
        C++;
        break;
      }
    }
  }
  cout << C << endl;
  return 0;
}