#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  for(int i = 0; i < n; ++i){
    ll a;
    cin >> a;
    fw.add(i,a);
  }
  while(q--){
    int op;
    cin >> op;
    if(op == 0){
      int pos;
      ll val;
      cin >> pos >> val;
      fw.add(pos,val);
    }
    else{
      int l,r;
      cin >> l >> r;
      cout << fw.sum(l,r) << '\n';
    }
  }
  return 0;
}