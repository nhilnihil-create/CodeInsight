#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  int num = 1;
  cin >> A >> B;
  
  if (B == 1) {
    num = 0;
  }

  while (A + (A - 1) * (num - 1) < B) {
    num += 1;
  }

  cout << num << endl;
}