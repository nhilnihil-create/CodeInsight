#include <bits/stdc++.h>

#include <vector>
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
using namespace std;

int main() {
  int mod = 1000000007;
  int s;
  cin >> s;
  long sum[s + 10];
  sum[0] = sum[1] = sum[2] = 0;
  sum[3] = 1;
  for (int i = 4; i <= s; i++) {
    sum[i] = (sum[i - 1] + sum[i - 3]) % mod;
  }
  cout << sum[s] << endl;
}