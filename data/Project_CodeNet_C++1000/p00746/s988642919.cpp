#include <iostream>
#include <cstdio>

using namespace std;

typedef pair<int, int> P;

P field[300];
int N;

void init() {

}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  while (true) {
    scanf("%d ", &N);
    if (N == 0) {
      return 0;
    }
    init();
    field[0].first = 0;
    field[0].second = 0;
    for (int i = 1; i < N; i++) {
      int n, d;
      scanf("%d %d ", &n, &d);
      int x = field[n].first;
      int y = field[n].second;
      field[i].first = x + dx[d];
      field[i].second = y + dy[d];
    }

    int minx = 0, miny = 0, maxx = 0, maxy = 0;
    for (int i = 0; i < N; i++) {
      int x = field[i].first;
      int y = field[i].second;
      minx = min(minx, x);
      miny = min(miny, y);
      maxx = max(maxx, x);
      maxy = max(maxy, y);
    }
    printf("%d %d\n", maxx - minx + 1, maxy - miny + 1);
  }
}