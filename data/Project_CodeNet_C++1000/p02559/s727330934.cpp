#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q;  cin >> n >> q;
  fenwick_tree<long long> ft(n);
  for (int i = 0; i < n; ++i){
    int ai; cin >> ai;
    ft.add(i, ai);
  }
  while (q--){
    int tp; cin >> tp;
    if(tp==0){
      int i, x; cin >> i >> x;
      ft.add(i, x);
    } else {
      int l, r; cin >> l >> r;
      cout << ft.sum(l,r) << "\n";
    }
  }
  return 0;
}