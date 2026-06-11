#include <iostream>
#include <vector>
#include <string>

using namespace std;

int H, W;

int Check(const vector<string>& grid) {
  vector<vector<int>> counts(H+1, vector<int>(W+1));
  for (int h = 0; h < H; ++h) {
    int start = -1;
    for (int w = 0, end = grid[0].size(); w < end; ++w) {
      if (grid[h][w] == '#') {
        if (start != -1) {
          for (int i = start; i < w; ++i) {
            counts[h][i] = w - start;
          }
        }
        start = -1;
        continue;
      }
      if (start == -1) start = w;
    }
  }
  int res = 0;
  for (int w = 0; w < W; ++w) {
    int start = -1;
    for (int h = 0, end = grid.size(); h < end; ++h) {
      if (grid[h][w] == '#') {
        if (start != -1) {
          for (int i = start; i < h; ++i) {
            counts[i][w] += h - start - 1;
            res = max(res, counts[i][w]);
          }
        }
        start = -1;
        continue;
      }
      if (start == -1) start = h;
    }
  }
  return res;
}

int main() {
  cin >> H >> W;
  vector<string> grid(H+1);
  for (int h = 0; h < H; ++h) {
    string s;
    cin >> s;
    grid[h] = s + '#';
  }
  grid[H] = string(W+1, '#');
  cout << Check(grid) << endl;
  
  return 0;
}
