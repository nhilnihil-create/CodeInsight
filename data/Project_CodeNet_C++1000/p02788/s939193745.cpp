#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
ll const inf = LLONG_MAX / 2;

// Verified: AOJ2644 Longest Match
// checked but not verified: sum_query
enum query_type { min_query, max_query, sum_query };

template<class T> struct segtree {
  int N;
  vector<T> dat, sum;
  function<T(T, T)> func;
  T ngvalue;

  void init(int n, function<T(T, T)> const& f, T ng) {
    N = 1;
    while(N < n) N <<= 1;
    dat.assign(2 * N - 1, 0);
    sum.assign(2 * N - 1, 0);
    func = f;
    ngvalue = ng;
  }

  segtree() = default;

  segtree(int n, query_type qtype) {
    if(qtype == min_query) {
      init(n, [](T a, T b){return min(a, b);}, numeric_limits<T>::max());
    }
    else if(qtype == max_query) {
      init(n, [](T a, T b){return max(a, b);}, numeric_limits<T>::min());
    }
    else if(qtype == sum_query) {
      init(n, [](T a, T b){return a + b;}, 0);
    }
    else {
      runtime_error("no matching query type");
    }
  }

  void add(int i, T x) {
    add(i, i + 1, x);
  }

  void add(int a, int b, T x) {
    add(a, b, x, 0, 0, N);
  }

  T add(int a, int b, T x, int k, int l, int r) {
    if(b <= l || r <= a) return dat[k];
    if(a <= l && r <= b) {
      sum[k] += x;
      return dat[k] += x;
    }
    int m = (l + r) / 2;
    return dat[k] = func(add(a, b, x, 2 * k + 1, l, m), add(a, b, x, 2 * k + 2, m, r)) + sum[k];
  }

  T operator()(int i) {
    return query(i, i + 1, 0, 0, N);
  }

  T operator()(int a, int b) {
    return query(a, b, 0, 0, N);
  }

  T query(int a, int b, int k, int l, int r) {
    if(b <= l || r <= a) return ngvalue;
    if(a <= l && r <= b) return dat[k];
    int m = (l + r) / 2;
    return func(query(a, b, 2 * k + 1, l, m), query(a, b, 2 * k + 2, m, r)) + sum[k];
  }
};

int main() {
  int N;
  ll D, A;
  cin >> N >> D >> A;

  vector<pair<ll, ll>> ms;

  rep(_, N) {
    ll x, h; cin >> x >> h;
    ms.emplace_back(x, h);
  }

  sort(ms.begin(), ms.end());
  segtree<ll> st(N, max_query);
  rep(i, N) {
    st.add(i, ms[i].second);
  }

  ms.emplace_back(inf, 0);

  ll ans = 0;
  rep(left, N) {
    auto x = ms[left].first;
    auto h = st(left);
    if (h <= 0) { continue; }
    auto cnt_bomb = (h - 1) / A + 1;
    ans += cnt_bomb;
    auto sum_damage = cnt_bomb * A;
    auto right = upper_bound(ms.begin(), ms.end(), make_pair(x + 2 * D, inf / 2)) - ms.begin();
//    cout << "left: " << left << ", right: " << right << "\n";
//    cout << "leftx: " << x << ", rightx: " << x + 2 * D << "\n";
    st.add(left, right, -sum_damage);
  }
  cout << ans << endl;
}
