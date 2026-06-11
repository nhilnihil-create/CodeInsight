#include <bits/stdc++.h>

using namespace std;
// (setq-default c-basic-offset 2)

void mark(vector<vector<bool>>& board, vector<vector<int>>& a, int bi) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a[i][j] == bi) {
        board[i][j] = true;
        return;
      }
    }
  }
}

bool check(vector<vector<bool>>& board) {
  for (int i = 0; i < 3; ++i) {
    bool ok = true;
    for (int j = 0; j < 3; ++j) {
      if (board[i][j] == false) {
        ok = false;
      }
    }
    if (ok) return true;
  }

  for (int i = 0; i < 3; ++i) {
    bool ok = true;
    for (int j = 0; j < 3; ++j) {
      if (board[j][i] == false) {
        ok = false;
      }
    }
    if (ok) return true;
  }

  bool ok = true;
  for (int i = 0; i < 3; ++i) {
    if (board[i][i] == false) {
      ok = false;
    }
  }
  if (ok) return true;

  ok = true;
  for (int i = 0; i < 3; ++i) {
    if (board[2 - i][i] == false) {
      ok = false;
    }
  }
  if (ok) return true;

  return false;
}

int main() {
  vector<vector<int>> a(3, vector<int>(3));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
    }
  }
  int n;
  cin >> n;
  vector<int> b(n);
  for (int& bi : b) {
    cin >> bi;
  }

  vector<vector<bool>> board(3, vector<bool>(3, false));
  for (int bi : b) {
    mark(board, a, bi);
  }

  if (check(board)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
