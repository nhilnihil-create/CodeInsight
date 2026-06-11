#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, h, C=0;
  cin >> N >> K;
  for (int i=0; i<N; i++) {
    cin >> h;
    if (K<=h) {
      C++;
    }
  }
  cout << C << endl;
}