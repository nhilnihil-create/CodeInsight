#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  int count = 1;
  while (N > 2*D+1) {
    count += 1;
    N -= 2*D+1;
  }
  cout << count << endl;
}