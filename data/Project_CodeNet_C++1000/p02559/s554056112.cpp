#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;

// 1-indexed
class BIT {
 public:
  ll n;                               //データの長さ
  vector<ll> bit;                     //データの格納先
  BIT(ll n) : n(n), bit(n + 1, 0) {}  //コンストラクタ

  // k & -kはLSB

  // bit_iにxをO(log(n))で加算する
  void add(ll i, ll x) {
    if (i == 0) return;
    for (ll k = i; k <= n; k += (k & -k)) {
      bit[k] += x;
    }
  }

  // bit_1 + bit_2 + …  + bit_n をO(log(n))で求める
  ll sum(ll i) {
    ll s = 0;
    if (i == 0) return s;
    for (ll k = i; k > 0; k -= (k & -k)) {
      s += bit[k];
    }
    return s;
  }

  // a_1 + a_2 + … + a_i >= x となるような最小のiを求める(a_k >= 0)
  // xが0以下の場合は該当するものなし→0を返す
  ll lower_bound(ll x) {
    if (x <= 0) {
      return 0;
    } else {
      ll i = 0;
      ll r = 1;
      //最大としてありうる区間の長さを取得する
      // n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
      while (r < n) r = r << 1;
      //区間の長さは調べるごとに半分になる
      for (int len = r; len > 0; len = len >> 1) {
        //その区間を採用する場合
        if (i + len < n && bit[i + len] < x) {
          x -= bit[i + len];
          i += len;
        }
      }
      return i + 1;
    }
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  BIT b(n);

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    b.add(i + 1, temp);
  }

  for (int i = 0; i < q; i++) {
    int p, q, r;
    cin >> p >> q >> r;

    if (p == 0) {
      b.add(q + 1, r);
    }

    if (p == 1) {
      cout << b.sum(r) - b.sum(q) << endl;
    }
  }
}
