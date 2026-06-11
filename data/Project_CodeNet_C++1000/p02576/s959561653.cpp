#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, T;
  cin >> N >> X >> T;
  auto cdiv = [&](auto a, auto b) {
    return (a + b - 1) / b;
  };
  cout << cdiv(N, X) * T << "\n";
}