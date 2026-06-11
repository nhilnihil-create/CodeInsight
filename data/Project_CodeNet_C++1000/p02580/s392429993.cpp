#include <bits/stdc++.h>

using namespace std;

const int SIZE_LIMIT = 3e5+5;
int sumH[SIZE_LIMIT], sumW[SIZE_LIMIT];
int indexH[SIZE_LIMIT], indexW[SIZE_LIMIT];

struct PairHash
{
  size_t operator()(const pair<int, int>& p) const {
    return p.first * 31 + p.second;
  }
};


bool cmpH(int i, int j) {
  return sumH[i] < sumH[j];
}

bool cmpW(int i, int j) {
  return sumW[i] < sumW[j];
}

unordered_set<pair<int, int>, PairHash> points;

int main() {
  memset(sumH, 0, sizeof(sumH)), memset(sumW, 0, sizeof(sumW));

  int h, w, m;
  scanf("%d%d%d", &h, &w, &m);

  for (int i = 0; i < SIZE_LIMIT; ++i) {
    indexW[i] = i, indexH[i] = i;
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    
    points.insert({x, y});
    sumH[x]++, sumW[y]++;
  }

  sort(indexH, indexH+h+1, cmpH);
  sort(indexW, indexW+w+1, cmpW);

  int maxh = sumH[indexH[h]], maxw = sumW[indexW[w]];
  for (int i = h; i > 0 && sumH[indexH[i]] == maxh; --i) {
    for (int j = w; j > 0 && sumW[indexW[j]] == maxw; --j) {
      if (points.find({indexH[i], indexW[j]}) == points.end()) {
        printf("%d\n", maxh+maxw);
        return 0;
      }
    }
  }
  printf("%d\n", maxh+maxw-1);
  return 0;
}