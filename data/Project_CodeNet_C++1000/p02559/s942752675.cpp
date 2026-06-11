#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  rep(i,n) {
    ll a;
    cin >> a;
    fw.add(i,a);
  }
  rep(i,q) {
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 0) fw.add(x,y);
    else cout << fw.sum(x,y) << endl;
  } 
  return 0; 
}