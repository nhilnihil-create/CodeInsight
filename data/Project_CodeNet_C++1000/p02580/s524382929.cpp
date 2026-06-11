#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using P = pair<int, int>;
 
int main() {
  int H, W, M;
  cin >> H >> W >> M;
 
  set<P> points;
  rep(i,0,M-1) {
    int h, w;
    cin >> h >> w;
    points.insert(P(h, w));
  }
 
  map<int, int> mp_rows, mp_columns;
  int max_row_cnt = 0;
  int max_column_cnt = 0;
 
  for (P point : points) {
    max_row_cnt = max(max_row_cnt, ++mp_rows[point.first]);
    max_column_cnt = max(max_column_cnt, ++mp_columns[point.second]);
  }
 
  vector<int> max_row_indices;
  for (auto mp_row : mp_rows) {
    if (max_row_cnt == mp_row.second)
      max_row_indices.push_back(mp_row.first);
  }
 
  vector<int> max_column_indices;
  for (auto mp_column: mp_columns) {
    if (max_column_cnt == mp_column.second)
      max_column_indices.push_back(mp_column.first);
  }
 
  int ans = max_row_cnt + max_column_cnt;
  for (auto h : max_row_indices) {
    for (auto w : max_column_indices) {
      if (points.find(P(h, w)) == points.end()) {
        cout << ans << endl;
        return 0;
      }
    }
  }
 
  cout << ans - 1 << endl;
  return 0;
}