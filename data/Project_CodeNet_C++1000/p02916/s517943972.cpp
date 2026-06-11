#include <iostream>
#include <vector>
using namespace std;

int main() {
  int size; cin >> size;
  vector<int> A(size), B(size), C(size-1);

  for (auto &a : A) {
    cin >> a;
  }

  for (auto &b : B) {
    cin >> b;
  }

  for (auto &c : C) {
    cin >> c;
  } 

  int res = 0;

  for (int i = 0; i < size; i++) {
    res = res + B[i];
    if (i < size - 1) {
      if (A[i] + 1 == A[i+1]) {
        res = res + C[A[i]-1];
      }
    }
  }

  cout << res << endl;


}