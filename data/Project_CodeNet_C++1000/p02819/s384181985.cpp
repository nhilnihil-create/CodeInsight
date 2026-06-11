#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x;
  cin >> x;

  vector<bool> is_prime(1000009, true);
  for (int i = 2; i < 1000009; ++i) {
    if (is_prime[i] == false) continue;
    if (i >= x) {
      cout << i << endl;
      return 0;
    }
    for (int j = 2 * i; j < 1000009; j += i) is_prime[j] = false;
  }
  return 0;
}