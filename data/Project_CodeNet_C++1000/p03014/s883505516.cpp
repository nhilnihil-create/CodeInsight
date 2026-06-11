#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hoge_rows(vector<string> &vec, vector<vector<int>> &rows, int h, int w,
              int pos_h, int pos_w = 0, int cnt = 0) {
  if (pos_w == w) {
    return cnt;
  } else if (vec[pos_h][pos_w] == '.') {
    return rows[pos_h][pos_w] =
               hoge_rows(vec, rows, h, w, pos_h, pos_w + 1, cnt + 1);
  } else {
    rows[pos_h][pos_w] = 0;
    hoge_rows(vec, rows, h, w, pos_h, pos_w + 1, 0);
    return cnt;
  }
}

int hoge_cols(vector<string> &vec, vector<vector<int>> &cols, int h, int w,
              int pos_h, int pos_w, int cnt = 0) {
  if (pos_h == h) {
    return cnt;
  } else if (vec[pos_h][pos_w] == '.') {
    return cols[pos_h][pos_w] =
               hoge_cols(vec, cols, h, w, pos_h + 1, pos_w, cnt + 1);
  } else {
    cols[pos_h][pos_w] = 0;
    hoge_cols(vec, cols, h, w, pos_h + 1, pos_w, 0);
    return cnt;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> vec(h);
  for (auto &v : vec)
    cin >> v;

  vector<vector<int>> rows(h, vector<int>(w, 0));
  vector<vector<int>> cols(h, vector<int>(w, 0));
  for (int i = 0; i < h; ++i)
    hoge_rows(vec, rows, h, w, i);
  for (int i = 0; i < w; ++i)
    hoge_cols(vec, cols, h, w, 0, i);

  int vmax = 0;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      vmax = max(vmax, cols[i][j] + rows[i][j] - 1);

  cout << vmax << endl;
}