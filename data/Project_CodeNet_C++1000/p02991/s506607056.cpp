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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    gr.at(a).push_back(b);
  }
  vector<vector<int>> chk(n, vector<int>(3, -1));
  int s, t;
  cin >> s >> t;
  s--; t--;
  chk.at(s).at(0) = 0;
  queue<pair<int, int>> q;
  q.push({s, 0});
  while(!q.empty()){
    auto p = q.front(); q.pop();
    for(int i : gr.at(p.first)){
      if(chk.at(i).at((p.second+1)%3) != -1) continue;
      chk.at(i).at((p.second+1)%3) = chk.at(p.first).at(p.second) + 1;
      q.push({i, (p.second+1)%3});
    }
  }
  if(chk.at(t).at(0) == -1) cout << -1 << endl;
  else cout << chk.at(t).at(0)/3 << endl;
  return 0;
}