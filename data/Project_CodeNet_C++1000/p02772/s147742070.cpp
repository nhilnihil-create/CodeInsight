#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N;
  while (cin >> A) {
    if (A % 2) continue;
    if (A % 3 && A % 5) return cout << "DENIED" << "\n", 0;
  }
  cout << "APPROVED" << "\n";
}