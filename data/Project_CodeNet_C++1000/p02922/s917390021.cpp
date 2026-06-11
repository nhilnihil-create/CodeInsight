#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C = 0, D = 1;
  cin >> A >> B; 
  while (D < B) {
    D--;
    D += A;
    C++;
  }
  cout << C << endl;
}