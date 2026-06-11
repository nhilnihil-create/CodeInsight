#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void fc(vector<int> &imos, int index, int a){
  int l = index - a;
  int r = index + a + 1;
  if(l < 0) l = 0;
  imos.at(l)++;
  if(imos.size() <= r) return ;
  imos.at(r)--;
  return ;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(snip_i, n) cin >> a.at(snip_i);
  rep(_, k){
    vector<int> imos(n, 0);
    bool fin = true;
    rep(i, n){
      fc(imos, i, a.at(i));
    }
    int co = 0;
    rep(i, n){
      co += imos.at(i);
      a.at(i) = co;
      if(a.at(i) != n) fin = false;
    }
    if(fin == true) break;
  }
  rep(i, n){
    if(i != 0) cout << " ";
    cout << a.at(i);
  }
  cout << endl;
  return 0;
}