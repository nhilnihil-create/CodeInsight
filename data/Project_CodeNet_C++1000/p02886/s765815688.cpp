#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum1 = 0;
  int sum2 = 0;
  for(int i = 0; i < N; i++) {
    int d;
    cin >> d;
    sum1 += d;
    sum2 += d * d;
  }
  cout << (sum1 * sum1 - sum2) / 2 << endl;
}