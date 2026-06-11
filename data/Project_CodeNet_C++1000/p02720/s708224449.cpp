#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<ll> lunlun;

int digit(ll x) {
  int res = 0;
  while (x) {
    x /= 10;
    ++res;
  }
  return res;
}

void rec(int d, ll lun) {
  if (digit(lun) == d) {
    lunlun.push_back(lun);
    return;
  }
  int lst = lun % 10;
  if (lst > 0) rec(d, 10*lun + lst-1);
  rec(d, 10*lun + lst);
  if (lst < 9) rec(d, 10*lun + lst+1);
  return;
}

int main() {
  int k;
  cin >> k;
  int d = 1;
  while (lunlun.size() < k) {
    for (ll lun = 1; lun <= 9; ++lun) rec(d, lun);
    ++d;
  }
  cout << lunlun[k-1] << endl;
  return 0;
}