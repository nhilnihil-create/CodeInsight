#include <bits/stdc++.h>
using namespace std;
int main()
  {int K, s{}; cin >> K;
  for (int a = 1; a <= K; ++a) for (int b = 1; b <= K; ++b) for (int c = 1; c <= K; ++c) s += gcd(gcd(a, b), c);
  cout << s << endl;}