#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout .tie(0);
  long long n;
  cin >> n;
  string k;
  while (n) {
    n -= 1;
    k.push_back('a' + n % 26LL);
    n /= 26LL;
  }

  for (int i = k.size(); i > 0; i--) cout << k[i - 1]; 
  return 0;
}
