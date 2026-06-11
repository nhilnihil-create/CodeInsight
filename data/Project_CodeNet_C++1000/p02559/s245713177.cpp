#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
using namespace atcoder;

int main(){
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> ft(n);
  rep(i, n){
    ll in;
    cin >> in;
    ft.add(i, in);
  }
  rep(_q, q){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 0) ft.add(b, c);
    else cout << ft.sum(b, c) << endl;
  }
  return 0;
}