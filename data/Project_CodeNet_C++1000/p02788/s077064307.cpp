#include<iostream>
#include<algorithm>
#include<cstdint>
#include<map>

int const MAXN = 2e5;
int const MAXNN = 1<<18;

std::pair<int, int> mon[MAXN];
int N, D, A, NN;

int dat_[MAXNN*2-1];
int laz_[MAXNN*2-1];

void init() {
  for(NN = 2; NN < N; NN<<=1);
  std::fill_n(dat_, NN*2-1, 0);
  std::fill_n(laz_, NN*2-1, 0);
}

void eval(int k) {
  if(laz_[k] == 0) return;
  if(k*2+1 < NN*2-1) {
    laz_[2*k+1] += laz_[k];
    laz_[2*k+2] += laz_[k];
  }
  dat_[k] += laz_[k];
  laz_[k] = 0;
}

int add(int a, int b, int x, int k, int l, int r) {
  if(b <= l || r <= a) {
    eval(k);
    return dat_[k];
  }
  if(a <= l && r <= b) {
    laz_[k] += x;
    return dat_[k] + laz_[k];
  }
  eval(k);
  int m = (l+r)/2;
  return dat_[k] = std::max(add(a, b, x, k*2+1, l, m), add(a, b, x, k*2+2, m, r));
}

int query(int a, int b, int k, int l, int r) {
  if(b <= l || r <= a) return -1;
  eval(k);
  if(a <= l && r <= b) return dat_[k];
  int m = (l+r)/2;
  bool intLeft = !(m <= a || b <= l);
  bool intRight = !(r <= a || b <= m);
  if(intLeft&intRight) return std::max(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
  if(intLeft) return query(a, b, k*2+1, l, m);
  return query(a, b, k*2+2, m, r);
}

void add(int a, int b, int x){ add(a, b, x, 0, 0, NN); }
int query(int a, int b){ return query(a, b, 0, 0, NN); }

int main() {
  std::cin >> N >> D >> A; D += D;
  for(int i = 0; i < N; ++i) {
    int X, H; std::cin >> X >> H;
    mon[i] = std::make_pair(X, (H+A-1)/A);
  }
  std::sort(mon, mon+N);
  init();
  for(int i = 0; i < N; ++i) add(i, i+1, mon[i].second);
 
  int64_t ans = 0; 
  int e = 0;
  for(int i = 0; i < N; ++i) {
    int c = query(i, i+1);
    if(c <= 0) continue;
    while(e < N && mon[e].first <= mon[i].first+D) ++e;
    add(i, e, -c);
    ans += (int64_t)c;
  }
  std::cout << ans << std::endl;
  return 0;
}
