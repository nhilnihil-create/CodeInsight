#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> gr(n, vector<int>(n));
  rep(i, n){
    rep(j, n){
      int in;
      cin >> in;
      gr.at(i).at(j) = in;
    }
  }
  vector<bool> chk(n, false);
  int ans = 0;
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, 0));
  int co = 0;
  while(!pq.empty()){
    auto p = pq.top(); pq.pop();
    if(chk.at(p.second) == true) continue;
    chk.at(p.second) = true;
    ans += p.first;
    // cerr << ans << endl;
    co++;
    if(co == n) break;

    rep(i, n){
      if(gr.at(p.second).at(i) == -1) continue;
      if(chk.at(i) == true) continue;
      pq.push(make_pair(-1*gr.at(p.second).at(i), i));
    }
  }
  cout << -1*ans << endl;
  return 0;
}
