#include<bits/stdc++.h>
using namespace std;

#define MAX_N 12

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  
  int column_count = m + 1; // c, A0, ..., Am
  vector<vector<int>> rows(n, vector<int>(column_count));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < column_count; j++) {
      cin >> rows.at(i).at(j);
    }
  }
  
  int min_price = -1;
  for (int tmp = 0; tmp < (1 << MAX_N); tmp++) {
    bitset<MAX_N> bit(tmp);
    
    // ビットが立っている位置の要素の合計をとる
    vector<int> sum(column_count, 0);
    for (int i = 0; i < n; i++) {
      if (!bit.test(i)) {
        continue;
      }
      
      for (int j = 0; j < column_count; j++) {
        sum.at(j) += rows.at(i).at(j);
      }
    }
    
    // 全ての理解度がX以上か判定する
    bool satisfied = true;
    for (int i = 1; i < column_count; i++) {
      if (sum.at(i) < x) {
        satisfied = false;
        break;
      }
    }
    
    if (satisfied) {
      if (min_price == -1) {
        min_price = sum.at(0);
      } else if (sum.at(0) < min_price) {
        min_price = sum.at(0);
      }
    }
    
    if (bit.count() == n) {
      // 全て調べ終わったので抜ける
      break;
    }
  }
  
  cout << min_price << endl;
}
