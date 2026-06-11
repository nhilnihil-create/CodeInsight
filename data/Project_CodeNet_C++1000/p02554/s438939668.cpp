#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
int MOD = 1e9 + 7;

ll mod(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}
    ll pow_kai(int a, int n)
{ //aのn乗を計算します。
    ll x = 1;
    rep(i, n)
    {
        x *= a;
        x %= MOD;
    }
    return x;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    ll Ans = pow_kai(10, N);
    ll temp = pow_kai(9, N);
    Ans -= (temp * 2);

    Ans += pow_kai(8, N);
    Ans = mod(Ans, MOD);
    cout << Ans << endl;
}
