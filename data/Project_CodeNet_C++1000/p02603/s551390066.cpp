#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  a.push_back(0);

  bool low = true;
  int tmp = 10010010;
  vector<int> ch;
  for (int num : a) {
    if (low) {
      if (tmp < num) {
        ch.push_back(tmp);
        low = false;
      }
    } else {
      if (tmp > num) {
        ch.push_back(tmp);
        low = true;
      }
    }
    tmp = num;
  }

  ll ans = 1000;
  for (int i = 0; i < ch.size()/2; ++i) {
    ll t = ans/ch[2*i];
    ans -= t*ch[2*i];
    ans += t*ch[2*i+1];
  }
  cout << ans << endl;
}