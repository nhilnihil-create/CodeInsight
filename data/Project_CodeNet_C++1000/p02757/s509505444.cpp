#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

// i の j 乗を取る関数　MODをとる
ll mpow(ll i, ll j)
{
  if (j == 0) return 1;
  ll res = mpow(i, j / 2) % MOD;
  res = (res * res) % MOD;
  return (j & 1) ? (res * i) % MOD : res;
}

ll comb(ll n, ll i)
{
  ll bunbo = 1, bunsi = 1;
  ll k = i;
  rep(j, k) {
    bunbo *= n;
    bunsi *= i;
    n--; i--;
  }
  return (bunbo / bunsi);
}

int main()
{
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  ll result = 0;
  reverse(s.begin(), s.end());
  if (p == 2) {
    rep(i,s.size()) {
      if ((s[i] - '0') % 2 == 0) {
        result += n-i;
      }
    }
  } else if (p == 5) {
    rep(i,s.size()) {
      if ((s[i] - '0') % 5 == 0) {
        result += n-i;
      }
    }
  } else {
    // 桁ごとにmodを求める
    vector<int> m(p, 0);
    vector<int> keta(200005, 0);
    int now = 0;
    ll ten = 1;
    rep(i,n) {
      keta[i] = (s[i] - '0') * ten % p;
      (ten *= 10) %= p;
    }

    // 累積和を求める
    rep(i,n) {
      now += keta[i];
      now %= p;
      m[now]++;
    }

    // modが同じ値になっているものの数で組み合わせを求める
    rep(i,p) {
      if (i == 0) result += m[i];
      result += comb(m[i], 2);
    }
  }
  cout << result << endl;
}

