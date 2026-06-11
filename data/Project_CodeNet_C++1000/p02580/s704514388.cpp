#include <bits/stdc++.h>
#define pvar(x) clog << "[" << #x << ":" << x << "]\n"
using namespace std;
using ll = long long int;
void solve() {
  int h, w, m, h1, w1;
  cin >> h >> w >> m;
  int mr = 0, mc = 0;
  map<int, int> r, c;
  set<pair<int, int>> s;
  for (int i = 0; i < m; i++) {
    cin >> h1 >> w1;
    r[h1]++, c[w1]++;
    mr = max(mr,r[h1]);
    mc = max(mc,c[w1]);
    s.insert({h1, w1});
  }
  set<int> row,col;
  for (auto i : r) {
    if (mr == i.second) {
      row.insert(i.first);
    }
  }
  for (auto i : c) {
    if (mc == i.second) {
      col.insert(i.first);
    }
  }
  
  for(auto i : row){
  	for(auto j : col){
  		if(s.find({i,j}) == s.end()){
  			cout<<mr+mc<<endl;
  			return;
  		}
  	}
  }

cout<<mr+mc-1<<endl; 
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
