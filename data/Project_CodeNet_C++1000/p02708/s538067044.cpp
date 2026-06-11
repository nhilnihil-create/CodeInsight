#include <bits/stdc++.h>
using namespace std;

const long mod = 1000000007;
long n, k;
int main() {
  cin >> n >> k;
  long sum = 0;
  for (int i = k; i <= n + 1; ++i) {
    sum = (sum + i * (n - i + 1) + 1) % mod;
  }
  cout << sum << endl;
}