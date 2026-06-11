#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;
  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }
  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }
  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main(){
  int n,q; cin>>n>>q;
  BinaryIndexedTree<ll> bit(n);
  rep(i,n){
    int a; cin>>a;
    bit.add(i,a);
  }
  while(q--){
    ll t; cin>>t;
    if(t==0){
      ll p,x; cin>>p>>x;
      bit.add(p,x);
    }else if(t==1){
      ll l,r; cin>>l>>r;
      ll ans = bit.sum(r-1) - bit.sum(l-1);
      cout << ans << endl;
    }
  }
  return 0;
}