#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int64_t N, M;
  cin >> N >> M;
  if (N % M <= M/2) {
    cout << N % M << endl;
  } else {
    cout << M - N % M << endl;
  }
}