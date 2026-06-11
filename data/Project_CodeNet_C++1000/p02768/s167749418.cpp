#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1000000007;

 
vector<long long> fact, finv, inv;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

void nCk(ll n, ll b) {
  finv[0] = finv[1] = 1;
  for (int i = 2; i < b + 5; i++)
  {
    finv[i] = finv[i - 1] * modinv(i, MOD);
    finv[i] %= MOD;
  }
  return ;
}

ll hoge (ll x) {
  ll y = 2;
  ll z = x;
  ll ans = 1;
  while (z)
  {
    if (z & 1)
    {
      ans *= y;
      ans %= MOD;
    }
    y *= y;
    y %= MOD;
    z >>= 1;
  }
  ans--;
  ans %= MOD;
  return ans;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll ans = hoge(n);
  cerr << ans << endl;

  finv.resize(b + 5);
  nCk(n, b);
  ll comA = 1;
  for (int i = 0; i < a; i++)
  {
    comA *= (n - i);
    comA %= MOD;
  }
  ll comB = comA;
  comA *= finv[a];
  comA %= MOD;
  ans -= comA;
  if (ans < 0)
  {
    ans += MOD;
  }
  ans %= MOD;

  for (int i = a; i < b; i++)
  {
    comB *= (n - i);
    comB %= MOD;
  }
  comB *= finv[b];
  comB %= MOD;

  ans -= comB;
  if (ans < 0)
  {
    ans += MOD;
  }
  
  ans %= MOD;
  cout << ans << endl; 
  
  return 0;
}
