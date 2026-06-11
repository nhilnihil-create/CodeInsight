#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,m; cin >>n >>m;
  int cnt = n-1;
  dsu d(n);
  rep(i,m){
    int a,b; cin >>a >>b;
    a--; b--;
    d.merge(a,b);
  }
  rep(i,n){
    if(d.leader(i)!=i) cnt--;
  }
  cout << cnt << endl;
  return 0;
}