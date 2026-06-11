#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  int a = 0;
  for (int i = 0; i + 1 < N; ++i) if (S[i] != S[i+1]) ++a;
  cout << N - 1 - max(a - K*2, 0) << endl;
}