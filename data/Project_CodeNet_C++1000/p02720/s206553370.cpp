#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  ll k;
  cin >> k;
  ll mx = max(k + 1, 10LL);
  vector<ll> lun(mx);
  rep(i, 10) {
    lun[i] = i;
  }
  if (k >= 10) {
    int count = 10;
    int base = 1;
    do {
      ll fst = lun[base] % 10;
      for (ll i = -1; i <= 1; i++) {
        if (count > k) break;
        if (fst + i >= 0 && fst + i <= 9) {
          lun[count] = lun[base] * 10 + fst + i;
          count++;
        }
      }
      base++;
    } while (count <= k);

  }

  cout << lun[k] << endl;

  return 0;
}
