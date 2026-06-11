#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  cout << setprecision(10) << (double)(N - N / 2) / (double)N << endl;
  return 0;
}