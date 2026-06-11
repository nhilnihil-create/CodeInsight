#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;

  cout << (N + ((D * 2) + 1) - 1) / ((D * 2) + 1) << endl;
  return 0;
}
