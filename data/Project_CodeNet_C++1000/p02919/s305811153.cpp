#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>BIT;
ll sumUp(int a) {
  ll ret = 0;
  while (a) {
    ret += BIT[a];
    a -= a & -a;
  }
  return ret;
}
void add(ll n, int v, int N) {
  while (v <= N) {
    BIT[v] += n;
    v += v & -v;
  }
}
int main () {
  int N;
  cin >> N;
  BIT.assign(200002, 0);
  vector<int>P(N + 2);
  vector<int>F(N + 2);
  for (int i = 2; i <= N + 1; i ++) {
    cin >> P[i];
    F[P[i]] = i;
  }
  add(1, F[N], N + 2);
  add(1, 1, N + 2);
  add(1, N + 2, N + 2);
  ll ans = 0;
  for (int i = N - 1; i >= 1; i --) {
    int mi = F[i];
    int ma = N + 2;
    ll ke = sumUp(F[i]);
    while (ma != mi) {
      int mu = (ma + mi) / 2;
      if (sumUp(mu) < ke + 1) mi = mu + 1;
      else ma = mu;
    }
    ll R1 = (ll)mi;
    ma = N + 2;
    ll R2 = (ll)N + 2;
    if ((int)R1 != N + 2) {
      ke ++;
      while (ma != mi) {
        int mu = (ma + mi) / 2;
        if (sumUp(mu) < ke + 1) mi = mu + 1;
        else ma = mu;
      }
      R2 = (ll)mi;
      ke --;
    }
    mi = 1;
    ma = F[i];
    while (ma != mi) {
      int mu = (ma + mi) / 2;
      if (sumUp(mu) < ke) mi = mu + 1;
      else ma = mu;
    }
    ll L1 = (ll)ma;
    ll L2 = 1;
    if (L1 > 1) {
      mi = 1;
      ke --;
      while (ma != mi) {
        int mu = (ma + mi) / 2;
        if (sumUp(mu) < ke) mi = mu + 1;
        else ma = mu;
      }
      L2 = (ll)mi;
    }
    ll kj = (ll)F[i];
    //cout << i << ' ' << L1 << ' ' << L2 << ' ' << R1 << ' ' << R2 << endl;
    ans += (ll)((R1 - kj) * (L1 - L2) + (R2 - R1) * (kj - L1)) * i;
    add(1, kj, N + 2);
  }
  cout << ans << endl;
}
