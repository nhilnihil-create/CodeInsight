#include <bits/stdc++.h>
using namespace std;
int main()
  {int A, B, C, K; cin >> A >> B >> C >> K;
  cout << min(A, K) - (K - min(A + B, K)) << endl;}