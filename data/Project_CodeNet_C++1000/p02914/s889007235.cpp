#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
typedef long long ll;
ll a[maxn], b[100];

bool ok[100];

void ins(ll x) {
  for (int i = 60; i >= 0; i--) if (!ok[i]) {
    if (x >> i & 1) {
        if (b[i]) x ^= b[i];
        else {
            b[i] = x;
            break;
        }
    }
  }
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
	scanf("%lld", &a[i]);
    for (int j = 60; j >= 0; j--)
      ok[j] ^= (a[i] >> j & 1);
  }
  for (int i = 1; i <= n; i++) ins(a[i]);
  ll ans1 = 0, ans2 = 0;
  for (int i = 60; i >= 0; i--) if (ok[i]) ans1 += 1ll << i;
  for (int i = 60; i >= 0; i--)
    for (int j = 60; j >= 0; j--) if (ok[j])
      b[i] &= ((1ll << 61) - 1 - (1ll << j));
  for (int i = 60; i >= 0; i--) if (!ok[i]) 
    ans2 = max(ans2, ans2 ^ b[i]);

//  for (int i = 60; i >= 0; i--) if (ok[i]) 
//    ans2 &= ((1ll << 61) - 1 - (1ll << i));
  cout << (ans1 + ans2 * 2) << endl;
}