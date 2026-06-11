#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main() {
  ll n, k, ans1 = 0, ans2 = 0;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i < j && a[i] > a[j])
        ans1++;
      else if (i > j && a[i] > a[j])
        ans2++;
    }
  }

  cout << ((ans1 * k) % mod +
           (((ans1 + ans2) % mod) * (((k * (k - 1)) / 2) % mod)) % mod) %
              mod
       << endl;
}