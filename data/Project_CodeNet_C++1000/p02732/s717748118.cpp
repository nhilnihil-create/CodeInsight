#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

ll cmb(ll n) {
  if(n < 0)
    return 0;
  else
    return n * (n - 1) / 2;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  rep(i, n) {
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
  }

  map<int, ll> ans;
  rep(i, cnt.size()) {
    int q = cnt[i];
    if(q == 0)
      continue;
    ll aa = cmb(q - 1);
    if(ans[q] == 0) {
      rep(j, cnt.size()) {
        if(j == i)
          continue;
        aa += cmb(cnt[j]);
      }
      ans[q] = aa;
    }
  }

  rep(i, n) cout << ans[cnt[a[i]]] << endl;
}
