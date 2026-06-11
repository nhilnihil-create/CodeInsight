#include <iostream>
#include <unordered_map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
  const int MAX = 300000;
  int H, W, M; 
  cin >> H >> W >> M;
  int h[MAX], w[MAX] = {0};
  for (int i = 0; i < M; i++) {
    cin >> h[i] >> w[i];
    h[i]--;
    w[i]--;
  }

  // Create unordered map to reference the existence of a bomb later
  // The key cannot be pair as long as I don't implement a has function for pair
  unordered_map<string, int> map;

  int rows[MAX], cols[MAX] = {0};

  int row_best_count = 0;
  int col_best_count = 0;

  for (int i = 0; i < M; i++) {
    string key = to_string(h[i]) + ',' + to_string(w[i]);
    map[key] = 1;

    rows[h[i]]++;
    cols[w[i]]++;

    row_best_count = max(row_best_count, rows[h[i]]);
    col_best_count = max(col_best_count, cols[w[i]]);
  }

  vector<int> best_rows;
  vector<int> best_cols;

  for (int i = 0; i < H; i++) {
    if (rows[i] == row_best_count) {
      best_rows.push_back(i);
    }
  }

  for (int i = 0; i < W; i++) {
    if (cols[i] == col_best_count) {
      best_cols.push_back(i);
    }
  }

  int ans = row_best_count + col_best_count - 1;
  for (int r : best_rows) {
    bool break_signal = false;
    for (int c : best_cols) {
      string key = to_string(r) + ',' + to_string(c);
      if (!map[key]) {
        ans = row_best_count + col_best_count;
        break_signal = true;
        break;
      }
    }

    if (break_signal) break;
  }

  cout << ans << endl;
}