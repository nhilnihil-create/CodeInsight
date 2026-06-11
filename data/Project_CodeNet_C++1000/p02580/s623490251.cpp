#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define REP(i,n) for(int i=0; i<(n); ++i)
int main()
{
  int h, w, m;
  cin >> h >> w >> m;
  vector<int> row(h), column(w);
  set<pair<int, int>> bomb;
  REP(i,m){
    int a,b;
    cin >> a >> b;
    --a; --b;
    ++row[a]; ++column[b];
    bomb.emplace(a,b);
  }
  int mh = 0, mw = 0 ; 
  vector<int> max_row, max_column;
  REP(i, h) mh = max(row[i], mh);
  REP(i, w) mw = max(column[i], mw);
  REP(i, h) if(mh == row[i]) max_row.push_back(i);
  REP(j, w) if(mw == column[j]) max_column.push_back(j);
  int ans = mh + mw;
  int faul = 0;
  for(int i:max_row) for(int j:max_column){
      if(bomb.count(P(i,j))) continue;
      cout << ans << endl;
      return 0;
  }
  --ans;
  cout << ans << endl;
  return 0;
}