#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, S;
  cin >> N >> K >> S;

  int rem = S + 1;
  if( S == 1000000000 ) rem = 1;
  vector<int> A(N, S + 1);
  for (int i = 0; i < K; i++) cout << S << ' ';
  for (int i = K; i < N; i++) cout << rem << ' ';
  cout << endl;
}