#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K, L = 1;
  cin >> N >> K;
  for (int i = 0; i > -1; i++) {
    if (N / K == 0) {break;}
    else {
      L++;
      N /= K;
    }
  }
  cout << L << endl;
}