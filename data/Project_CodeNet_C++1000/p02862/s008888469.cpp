//競技プログラミング用のテンプレート
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <stack>
#include <limits>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repr(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;
//エイリアス
using ll = long long int;
using p = pair<int, int>;
using pl = pair<ll, ll>;
using v = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vl = vector<ll>;

//定数
const int intmax = numeric_limits<int>::max();
const ll llmax = numeric_limits<ll>::max();
const ll mod = 1e9 + 7;
const double pi = M_PI;



ll x, y;
ll cand[1000000 + 1];

void init() {
  cand[0] = 1;
  cand[1] = 1;
  for(ll i = 2; i < 1000000 + 1; i++) {
    cand[i] = i * cand[i - 1];
    cand[i] %= mod;
  }
}
template <typename number>
pair<number, number> extended_euclid(number a, number b)
{
  number r0, r1, a0, a1, b0, b1;
  r0 = a; r1 = b;
  a0 = 1; a1 = 0;
  b0 = 0; b1 = 1;
  while (r1>0) {
    number q1 = r0 / r1;
    number r2 = r0 % r1;
    number a2 = a0 - q1 * a1;
    number b2 = b0 - q1 * b1;
    r0 = r1 ; r1 = r2;
    a0 = a1 ; a1 = a2;
    b0 = b1 ; b1 = b2;
  }
  number c = r0;
  a = a0; //x
  b = b0; //y
  return  {a, c};
}

template  <typename number>
number inverse_N(number a, number N)
{
  pair<number, number> result = extended_euclid(a, N);
  if(result.first < 0)
  {
    result.first = result.first + N;
  }
  return result.first;
}


ll calc_cands(ll fixed) {
  ll restx_twice = x - fixed;
  ll resty = y - fixed * 2;
  if (restx_twice % 2 != 0) return 0;
  ll restx = restx_twice / 2;
  if (restx < 0) return 0;
  if (resty < 0) return 0;
  if (restx != resty) return 0;
  if (restx + fixed >= max(x, y) + 1) return 0;
  ll total = restx + fixed;
  ll bunbo = cand[total - fixed] * cand[fixed];
  bunbo %= mod;
  ll bunbo_inv = inverse_N(bunbo, mod);
  ll result = cand[total] * bunbo_inv;
  result %= mod;
  return result;
}

int main()
{
  cin >> x >> y;
  init();
  ll result = 0;
  rep(i, max(x, y) + 1) {
    result += calc_cands(i);
    result %= mod;
  }
  cout << result << endl;
}
