#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  int p = 2*d + 1;
  cout << (n + (p - 1)) / p << endl;
}