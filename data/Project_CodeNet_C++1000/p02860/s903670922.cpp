#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  bool isRotated = false;
  if (N % 2 == 1) {
    cout << "No" << endl;
    return 0;
  } else {
    for (int i = 0; i < N / 2; i++) {
      if (S.at(i) != S.at(N / 2 + i)) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
}
