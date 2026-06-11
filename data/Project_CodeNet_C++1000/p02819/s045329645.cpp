#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool judge_prime(int num) {
  bool can = true;
  for (int i = 3; i < num; i += 2) {
    if (num % i == 0) {
      can = false;
      break;
    }
  }
  if (can) return true;
  else return false;
}

int main() {
  int N;
  cin >> N;
  if (N == 2) cout << 2 << endl;
  else {
    if (N % 2 == 0) N++;
    N -= 2;
    bool prime = false;
    while(!prime) {
      N += 2;
      if (judge_prime(N)) {
        cout << N << endl;
        break;
      }
    }
  }
}
