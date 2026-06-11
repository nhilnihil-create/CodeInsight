#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  int r, c;
  fscanf(stdin, "%d %d", &r, &c);
  vector<vector<int> > table(r + 1, vector<int>(c + 1));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      fscanf(stdin, "%d", &table[i][j]);
    }
  }
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      table[i][c] += table[i][j];
      table[r][j] += table[i][j];
    }
    table[r][c] += table[i][c];
  }
  for (int i = 0; i <= r; ++i) {
    for (int j = 0; j <= c; ++j) {
      if (j) { fprintf(stdout, " "); }
      fprintf(stdout, "%d", table[i][j]);
    }
    fprintf(stdout, "\n");
  }
  return 0;
}