#include <bits/stdc++.h>
using namespace std;

long double A, B, C;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> A >> B >> C;
  cout << (C > 2 * sqrt(A * B) + A + B ? "Yes" : "No") << "\n";
}