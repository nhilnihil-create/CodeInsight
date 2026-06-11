#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll cnt[1000010];
int main() {
  for (int i = 1; i <= 1000000; i ++) {
    for (int j = i; j <= 1000000; j += i) {
      cnt[j] ++;
    }
  }
  ll s = 0;
  ll n; cin >> n;
  for (int i = 1; i < n; i ++) {
    s += cnt[i];
  }
  cout << s << endl;
  return 0;
}