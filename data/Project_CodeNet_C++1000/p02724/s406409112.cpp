#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  cin >> A;
  int B = A % 500;
  cout << A / 500 * 1000 + B / 5 * 5 << endl;
 }
