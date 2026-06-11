#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int N = (int)1e5 + 5;
const int A = 60;

ll n, a[N], cnt[A], basis[A];

void init() {
  cin >> n;
  for(int i = 0 ; i < n ; ++i) {
    cin >> a[i];
    for(int j = 0 ; j < A ; ++j) if((1LL << j) & a[i]) cnt[j]++;
  }
}
void solve() {
  ll ans = 0;
  for(int j = 0 ; j < A ; ++j) if(cnt[j] % 2) {
    for(int i = 0 ; i < n ; ++i) if((1LL << j) & a[i]) a[i] ^= (1LL << j);
    ans += (1LL << j);
  }

  for(int i = 0 ; i < n ; ++i) {
    for(int j = A - 1 ; j >= 0 ; --j) {
      if(a[i] & (1LL << j)) {
        if(!basis[j]) {
          basis[j] = a[i];
          break;
        }
        a[i] ^= basis[j];
      }
    }
  }

  ll ans2 = 0;
  for(int j = A - 1 ; j >= 0 ; --j) {
    if(!basis[j] || (ans2 & (1LL << j))) continue;
    ans2 ^= basis[j];
  }

  cout << ans + ans2 * 2 << '\n';
}

int main() {
  init();
  solve();
}
