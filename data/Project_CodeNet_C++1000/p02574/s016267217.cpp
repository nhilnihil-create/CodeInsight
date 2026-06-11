#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int B[1000001];
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int d = 0;
  bool c = false;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    d = gcd(d, A[i]);
    B[A[i]]++;
  }
  for (int i = 2; i < 1000001; i++) {
    int count = 0;
    for (int j = 1; j * i < 1000001; j++) {
      count += B[i * j];
    }
    if (count > 1)
      c = true;
  }
  if (d != 1)
    puts("not coprime");
  else if (c)
    puts("setwise coprime");
  else
    puts("pairwise coprime");
}