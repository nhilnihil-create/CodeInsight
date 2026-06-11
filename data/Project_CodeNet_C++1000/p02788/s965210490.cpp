#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

struct LazySegmentTree {
  //10^6要素まで対応
  vector<ll> d, lazy;
  int size = 1;
  LazySegmentTree(): d(1<<21, 0), lazy(1<<21, 0) {} //addなので0初期化

  //functions
  //OPERATION: ADD
  //init
  void init_LazySegmemtTree(vector<ll>&original) {
    int n = original.size();
    while (size < n) size *= 2;
    if (size > (1<<20)) cout << "Too Many Elements" << endl; //error
    for (int i = 0; i < n; i++) d[size+i] = original[i];
    for (int i = size-1; i > 0; i--) d[i] = d[2*i] + d[2*i+1]; //add
    return;
  }
  //init-初期値0でサイズだけ指定するとき
  void init_LazySegmentTree_size(int n) {
    while (size < n) size *= 2;
    return;
  }

  //d[k]の確定
  void eval(int k) {
    if (lazy[k] == 0) return;
    if (k < size) {
      lazy[2*k] += lazy[k] / 2;
      lazy[2*k+1] += lazy[k] / 2;
    }
    d[k] += lazy[k];
    lazy[k] = 0;
    return;
  }

  //update: 区間[a, b)にx加算
  void update(int a, int b, ll x, int k=1, int l=0, int r=-1) {
    eval(k);
    if (r == -1) r =size;
    if ((r <= a) || (b <= l)) return;
    if ((a <= l) && (r <= b)) {
      lazy[k] += x * (r - l);
      eval(k);
      return;
    }
    else {
      update(a, b, x, 2*k, l, (l+r)/2);
      update(a, b, x, 2*k+1, (l+r)/2, r);
      d[k] = d[2*k] + d[2*k+1];
      return;
    }
  }

  //query: [a, b)の区間の総和(add)
  ll query(int a, int b=-1, int k=1, int l=0, int r=-1) {
    if (b == -1) b = a + 1;
    if (r == -1) r = size;
    //範囲がまったく重ならないとき(add)
    if ((r <= a) || (b <= l)) return 0;
    //範囲が重なるとき（参照するとき）
    eval(k);
    //範囲に含まれるとき
    if ((a <= l) && (r <= b)) return d[k];
    //一部重なるとき(add)
    else return query(a, b, 2*k, l, (l+r)/2) + query(a, b, 2*k+1, (l+r)/2, r);
  }

  int lower_bound(ll target) {
    int k = 1;
    eval(k);
    if (target > d[1]) return size;
    while (k < size) {
      eval(2*k);
      if (target > d[2*k]) {
        target -= d[2*k];
        k = 2 * k + 1;
        eval(k);
      }
      else k = 2 * k;
    }
    return k - size;
  }

  void printSegmentTree() {
    bool printflag = false;
    if (!printflag) return;
    cout << "-----printSegmentTree begin-----" << endl;
    for (int i = 1; i < 2*size; i++) cout << i << ": " << d[i] << " " << lazy[i] << endl;
    cout << "------printSegmentTree end------" << endl;
    return;
  }
};

//------------更新------------
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, d, a;
  cin >> n >> d >> a;
  vector<pll> monsters(n);
  for (int i = 0; i < n; i++) cin >> monsters[i].first >> monsters[i].second;
  sort(monsters.begin(), monsters.end());

  vector<ll> effindex(n);
  ll eff = 0;
  for (int i = 0; i < n; i++) {
    while ((eff != n) && (monsters[eff].first - monsters[i].first <= 2 * d)) eff++;
    effindex[i] = eff;
  }

  vector<ll> hs(n);
  for (int i = 0; i < n; i++) hs[i] = monsters[i].second;
  LazySegmentTree lst;
  lst.init_LazySegmemtTree(hs);

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (lst.query(i) <= 0) continue;
    ll bomb = (lst.query(i) - 1) / a + 1;
    lst.update(i, effindex[i], - (a * bomb));
    ans += bomb;
  }
  cout << ans << endl;
}
