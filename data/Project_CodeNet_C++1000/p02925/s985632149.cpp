#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  map<pair<int, int>, int> tr;
  vector<vector<int>> gr(n*(n-1)/2, vector<int>());
  vector<vector<int>> num(n, vector<int>(n-1));
  vector<int> deg(gr.size(), 0);
  int co = 0;
  rep(i, n){
    rep(j, n-1){
      int in;
      cin >> in;
      in--;
      pair<int, int> p(i, in);
      if(p.first > p.second) swap(p.first, p.second);
      if(tr.count(p) != 1){
        tr[p] = co;
        co++;
      }
      num.at(i).at(j) = tr[p];
    }
  }
  rep(i, n){
    int bf = num.at(i).at(0);
    rep2(j, 1, n-1){
      int now = num.at(i).at(j);
      gr.at(bf).push_back(now);
      deg.at(now)++;
      bf = now;
    }
  }

  queue<int> q;
  rep(i, deg.size()){
    if(deg.at(i) == 0)q.push(i);
  }
  vector<int> topo;
  while(!q.empty()){
    int fr = q.front(); q.pop();
    for(auto i : gr.at(fr)){
      deg.at(i)--;
      if(deg.at(i) == 0) q.push(i);
    }
    topo.push_back(fr);
  }
  if(topo.size() != deg.size()){
    cout << -1 << endl;
    return 0;
  }
  
  vector<int> dp(n*(n-1)/2, 1);
  for(auto i : topo){
    for(auto j : gr.at(i)){
      dp.at(j) = max(dp.at(j), dp.at(i)+1);
    }
  }
  int ans = 0;
  rep(i, dp.size()){
    ans = max(ans, dp.at(i));
  }
  cout << ans << endl;
  return 0;
}