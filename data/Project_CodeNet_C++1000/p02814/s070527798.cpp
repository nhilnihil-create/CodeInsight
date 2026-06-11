#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

int F(int x) {
  int res = 0;
  while (x%2 == 0) {
    res++;
    x /= 2;
  }
  return res;
}

int main() {
  // 因数2に注目、2で割れる回数が同じが条件、最小公倍数がオーバーフローに注意
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int time = F(A[0]); // 最初の数が何回2で割れるか
  rep(i, N) {
    if (F(A[i]) != time) {
      cout << 0 << '\n';
      return 0;
    }
    A[i] >>= time;
  }
  ll l = 1;
  rep(i, N) {
    l = lcm(l, A[i]);
    if (l > M) {
      cout << 0 << '\n';
      return 0;
    }
  }
  M >>= (time-1);
  M /= l;
  int ans = (M+1) / 2;
  cout << ans << '\n';  
  return 0;
}