#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  s.push_back('R');
  vector<int> ans(s.size()-1, 0);
  bool mode = false;
  int co = 1, li;
  rep2(i, 1, s.size()){
    if(mode == false){
      if(s.at(i) == 'R') co++;
      else{
        mode = true;
        ans.at(i) += co/2;
        ans.at(i-1) += (co+1)/2;
        co = 1;
        li = i;
      }
    }else{
      if(s.at(i) == 'L') co++;
      else{
        mode = false;
        // cerr << li << " " << co << " " << i << endl;
        ans.at(li) += (co+1)/2;
        ans.at(li-1) += co/2;
        co = 1;
      }
    }
  }
  rep(i, ans.size()){
    if(i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}