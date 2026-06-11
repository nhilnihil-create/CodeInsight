#include <bits/stdc++.h>

/**
 * @title Fenwick tree (Add)
 * @docs fenwick_tree_add.md
 */
template <typename T>
class FenwickTreeAdd {
  using value_type = T;

  int size;
  std::vector<value_type> data;

public:
  FenwickTreeAdd(){}
  FenwickTreeAdd(int size): size(size), data(size + 1, 0){}

  void update(int i, value_type val){
    i += 1; // 1-index

    while(i <= size){
      data[i] = data[i] + val;
      i += i & (-i);
    }
  }

  value_type get(int i) const { // [0, i)
    value_type ret = 0;
    i += 1; // 1-index

    while(i > 0){
      ret = ret + data[i];
      i -= i & (-i);
    }

    return ret;
  }

  value_type get(int l, int r) const { // [l, r)
    return get(r - 1) - get(l - 1);
  }
};


int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  FenwickTreeAdd<int64_t> s(N);

  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i){
    std::cin >> a[i];
    s.update(i, a[i]);
  }

  for(int i = 0; i < Q; ++i){
    int type; std::cin >> type;
    if(type == 0){
      int p, x; std::cin >> p >> x;
      s.update(p, x);
    }else{
      int l, r; std::cin >> l >> r;
      std::cout << s.get(l, r) << "\n";
    }
  }



  return 0;
}
