#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, K;
  cin >> A >> B >> K;
  long a = max(0L, A - K);
  long b = max(0L, B - (K - (A - a)));
  cout << a << "\n";
  cout << b << "\n";
}