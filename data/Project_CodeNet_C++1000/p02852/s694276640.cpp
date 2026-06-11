#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int pos = n;
  vector<int> ans;
  while(1){
    bool f = false;
    rep(i, m){
      int nx = pos - m + i;
      if(nx < 0) continue;
      if(s.at(nx) == '0'){
        f = true;
        pos = nx;
        ans.push_back(m-i);
        break;
      }
    }
    if(f == false){
      cout << -1 << endl;
      return 0;
    }
    if(pos == 0){
      rrep(i, ans.size()){
        if(i != ans.size() - 1) cout << " ";
        cout << ans.at(i);
      }
      cout << endl;
      return 0;
    }
  }
  return 0;
}