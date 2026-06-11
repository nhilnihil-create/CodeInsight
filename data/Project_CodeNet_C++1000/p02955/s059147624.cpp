#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector < int > a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  vector < int > factors;
  for (int i = 1; i <= sqrt(sum); i++) {
    if (sum % i == 0) {
      if (i * i != sum) factors.push_back(i);
      factors.push_back(sum / i);
    }
  }

  sort (factors.begin(), factors.end(), greater < int > ());
  for (auto g : factors) {
    vector < int > r;
    for (int i = 1; i <= n; i++) r.push_back(a[i] % g);
    sort (r.begin(), r.end());
    vector < int > lt (n, 0), rt(n, 0);
    lt[0] = r[0];
    for (int i = 1; i < n; i++) lt[i] = r[i] + lt[i - 1];
    rt[n - 1] = g - r[n - 1];
    for (int i = n - 2; i >= 0; i--) rt[i] = g - r[i] + rt[i + 1];
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      if (lt[i] == rt[i + 1] && lt[i] <= k) ok = true;
    }
    if (ok) {
      cout << g << '\n';
      return 0;
    }
  }
  cout << 1 << '\n';
}
