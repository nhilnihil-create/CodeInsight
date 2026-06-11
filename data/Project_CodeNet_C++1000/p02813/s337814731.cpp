#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  
  vector<int> o(n);
  rep(i, n) o[i] = i+1;
  
  bool flga, flgb;
  int cnt=0;
  int a, b;
  do
  {
    flga = flgb = true;
    rep(i, n){
      if (p[i]!=o[i]) flga=false;
      if (q[i]!=o[i]) flgb=false;
    }
    
    if (flga) a = cnt;
    if (flgb) b = cnt;
    
    cnt++;
  } while (next_permutation(o.begin(), o.end()));
  
  cout << abs(a-b) << endl;
  return 0;
}
