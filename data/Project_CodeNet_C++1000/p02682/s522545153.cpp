#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  if (K <= A) return cout << K << "\n", 0;
  if (K <= A + B) return cout << A << "\n", 0;
  cout << A - (K - A - B) << "\n";
}