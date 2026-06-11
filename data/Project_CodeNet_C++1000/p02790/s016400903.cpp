#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string A, B;
  for (int i = 0; i < b; i++) {
    A += char('0' + a);
  }
  for (int i = 0; i < a; i++) {
    B += char('0' + b);
  }
  cout << ((A < B) ? A : B) << "\n";
}