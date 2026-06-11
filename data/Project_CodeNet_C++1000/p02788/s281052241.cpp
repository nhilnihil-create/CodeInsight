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

struct SegmentTree {
  //10^6要素まで対応
  vector<ll> d;
  int size = 1;
  SegmentTree(): d(1<<21, 0) {} //addなので0初期化

  //functions
  //OPERATION: ADD
  //init
  void init_SegmemtTree(vector<ll>&original) {
    int n = original.size();
    while (size < n) size *= 2;
    if (size > (1<<20)) cout << "Too Many Elements" << endl; //error
    for (int i = 0; i < n; i++) d[size+i] = original[i];
    for (int i = size-1; i > 0; i--) d[i] = d[2*i] + d[2*i+1]; //add
  }

  //update: k番目にa加算
  void update(int k, ll a) {
    k += size;
    ll temp = 0;
    while(k > 0) {
      d[k] += a - temp;
      k /= 2;
    }
  }

  //query: [a, b)の区間の総和(add)
  ll query(int a, int b, int k=1, int l=0, int r=-1) {
    if (r == -1) r = size;
    //範囲がまったく重ならないとき(add)
    if ((r <= a) || (b <= l)) return 0;
    //範囲に含まれるとき
    if ((a <= l) && (r <= b)) return d[k];
    //一部重なるとき(add)
    else return query(a, b, 2*k, l, (l+r)/2) + query(a, b, 2*k+1, (l+r)/2, r);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, d, a;
  cin >> n >> d >> a;
  vector<pll> monster(n);
  for (int i = 0; i < n; i++) cin >> monster[i].first >> monster[i].second;
  sort(monster.begin(), monster.end());

  vector<int> effindex(n);
  //i番目が巻き込まれるときの左端
  int l = n-1;
  for (int r = n-1; r >= 0; r--) {
    while ((l >= 0) && (monster[r].first - monster[l].first <= 2 * d)) l--;
    effindex[r] = l+1;
  }
  //for (int i = 0; i < n; i++) cout << effindex[i] << " ";
  //cout << endl;

  vector<ll> zeros(n, 0);
  SegmentTree st;
  st.init_SegmemtTree(zeros);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll cnt;
    if (i == 0) {
      cnt = (monster[i].second - 1) / a + 1;
      st.update(i, cnt);
    }
    else {
      cnt = (monster[i].second - a * st.query(effindex[i], i) <= 0) ? 0 : (monster[i].second - a * st.query(effindex[i], i) - 1) / a + 1;
      st.update(i, cnt);
    }
    ans += cnt;
  }
  cout << ans << endl;
}
