#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

template <typename T = long long>
struct BinaryIndexedTree_RangeAdd {
  vector<T> dat1;
  vector<T> dat2;
  BinaryIndexedTree_RangeAdd(int n) : dat1(n + 1, 0), dat2(n + 1, 0) {}
  void add_range(int l, int r, T w) {  // add w [l,r)
    for (int k = l + 1; k < (int)dat1.size(); k += k & -k) dat1[k] -= w * l;
    for (int k = r + 1; k < (int)dat1.size(); k += k & -k) dat1[k] += w * r;
    for (int k = l + 1; k < (int)dat2.size(); k += k & -k) dat2[k] += w;
    for (int k = r + 1; k < (int)dat2.size(); k += k & -k) dat2[k] -= w;
  }
  T sum(int x) {  // sum [0,x)
    T s = 0;
    for (int k = x; k > 0; k &= k - 1) s += dat1[k];
    for (int k = x; k > 0; k &= k - 1) s += dat2[k] * x;
    return s;
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long N, D, A;
  cin >> N >> D >> A;
  BinaryIndexedTree_RangeAdd<long long> bit(N);
  vector<pair<long long, long long> > XH(N);
  for (int i = 0; i < N; i++) {
    cin >> XH[i].first >> XH[i].second;
  }
  sort(XH.begin(), XH.end());
  for (int i = 0; i < N; i++) {
    bit.add_range(i, i + 1, XH[i].second);
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long tmp = bit.sum(i + 1) - bit.sum(i);
    if (tmp <= 0) continue;
    long long count = (tmp - 1) / A + 1;
    ans += count;
    int j = lower_bound(
                XH.begin(), XH.end(),
                pair<long long, long long>(XH[i].first + 2 * D + 1, -INT_MAX))
            - XH.begin();
    bit.add_range(i, j, -count * A);
  }
  cout << ans << endl;
  return 0;
}
