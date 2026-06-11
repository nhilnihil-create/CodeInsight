#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string S, T;
  for (int i = 0; i < b; i++) {
    S += char('0' + a);
  }
  for (int i = 0; i < a; i++) {
    T += char('0' + b);
  }
  if (S > T) swap(S, T);
  cout << S << "\n";
}