#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  int64_t C = 0;
  for (int64_t i=1; i<=N; i++) {
    C += (i + (N - N%i)) * ((N - N%i) / i) / 2;
    //cout << C << endl;
  }
  cout << C << endl;
}