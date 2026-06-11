#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  int current;
  int last = 0;
  ll steps = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> current;
    if (last > current) {
      steps += last - current;
    } else {
      last = current;
    }
  }
  cout << steps << endl;
}