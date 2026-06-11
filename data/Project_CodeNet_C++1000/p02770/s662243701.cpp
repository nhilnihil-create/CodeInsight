#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int divceil(int a, int b) {
  return (a+b-1)/b;
}

int main() {
  int k, q;
  cin >> k >> q;
  int d[k];
  for (int i = 0; i < k; ++i) cin >> d[i];
  
  for (int i = 0; i < q; ++i) {
    int n, x, m;
    cin >> n >> x >> m;
    ll last = x, eq = 0;
    for (int i = 0; i < k; ++i) {
      ll num = divceil(n-1-i, k);
      last += (d[i]%m)*num;
      if (d[i]%m == 0) eq += num;
    }
    ll ans = (n-1) - (last/m - x/m) - eq;
    cout << ans << endl;
  }
  return 0;
}