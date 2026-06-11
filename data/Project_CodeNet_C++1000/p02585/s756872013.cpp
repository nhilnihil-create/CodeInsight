#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < n; i++)

int main() {
  ll n,k;
  cin >> n >> k;
  int p[n];
  ll c[n];
  rep(i,n) {
    cin >> p[i];
    p[i]--;
  }
  rep(i,n) cin >> c[i];
  ll ans = -1000000000000;
  rep(i,n) {
    int now = i;
    ll cycle_score = 0;
    int cycle_len = 0;
    while (1) {
      now = p[now];
      cycle_score += c[now];
      cycle_len++;
      if (now == i) break;
    }
    //printf("%d %lld\n", cycle_len, cycle_score);
    now = i;
    ll cnt = 0;
    int len = 0;
    while (1) {
      len++;
      now = p[now];
      cnt += c[now];
      int num = (k-len) / cycle_len;
      ll score = cnt + max(0ll,cycle_score)*num;
      ans = max(ans,score);
      if (now == i || len == k) break;
    }
  }
  cout << ans << endl;
  return 0;
}


