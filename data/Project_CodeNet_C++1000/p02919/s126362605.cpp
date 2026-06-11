#include<iostream>
#include<numeric>
#include<functional>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXN = 2e5;
int const MAXNN = 1<<18;

template<typename T, int MAXNN>
struct seg_tree {
  typedef std::function<T(T,T)> OP;
  T data_[MAXNN*2-1], e_;
  int NN;
  OP& op_;
  
  seg_tree(int N, OP& op, T e) : op_(op), e_(e) {
    NN = 1;
    while(NN < N) NN *= 2;
    std::fill_n(data_, NN*2-1, e);
  }
  void update(int k, T v) {
    k += NN-1;
    data_[k] = v;
    while(k > 0) {
      k = (k-1)/2;
      data_[k] = op_(data_[k*2+1], data_[k*2+2]);
    }
  }
  int query(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return e_;
    if(a <= l && r <= b) return data_[k];
    int m = (l+r)/2;
    int vl = query(a, b, k*2+1, l, m);
    int vr = query(a, b, k*2+2, m, r);
    return op_(vl, vr);
  }
  int query(int a, int b){ return query(a, b, 0, 0, NN); }
};

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

int ix[MAXN+1];

int main() {
  int N = getZ();
  seg_tree<int64_t, MAXNN>::OP op = [](int64_t x, int64_t y){ return std::max(x, y); };
  seg_tree<int64_t, MAXNN> s(N, op, 0);
  for(int i = 0; i < N; ++i) s.update(i, getZ());
  int64_t ans = 0;
  std::iota(ix, ix+N+1, 0); // 0 ... N
  for(int i = 0; i < N; ++i) {
    int p = s.query(i, i+1);
    int il2 = -1, il1 = -1, ir1 = N, ir2 = N;
    // search left
    il1 = i - *std::partition_point(ix, ix+i+1, [&](int j){ return s.query(i-j, i) <= p; });
    // search right
    ir1 = i + *std::partition_point(ix, ix+N-i, [&](int j){ return s.query(i, i+j+1) <= p; });
    if(il1 >= 0) {
      il2 = il1 - *std::partition_point(ix, ix+il1+1, [&](int j){ return s.query(il1-j, il1) <= p; });
      ans += (int64_t)(il1 - il2)*(ir1 - i)*p;
    }
    if(ir1 < N) {
      ir2 = ir1 + *std::partition_point(ix, ix+N-ir1, [&](int j){ return s.query(ir1+1, ir1+j+1) <= p; });
      ans += (int64_t)(i - il1)*(ir2 - ir1)*p;
    }
  }
  fin(ans);
  return 0;
}
