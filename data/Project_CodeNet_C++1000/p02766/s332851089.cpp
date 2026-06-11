#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int digit = 1;
  int L = M;
  while (N >= L) {
    digit += 1;
    L *= M;
  }
  cout << digit << endl;
}