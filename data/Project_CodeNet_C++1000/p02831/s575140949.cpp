#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int A, B;
  cin >> A >> B;
  for (int64_t i = 1; i <= 100000; i++) {
    int64_t j = A * i;
    if (j % B == 0) {
      cout << j << endl;
      break;
    }
  }   
}