#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int m;
int dx[256];
int dy[256];
int xs[256];
int ys[256];
bool field[100][100];


int main() {
  dx['N'] = 0;
  dy['N'] = 1;
  dx['S'] = 0;
  dy['S'] = -1;
  dx['E'] = 1;
  dy['E'] = 0;
  dx['W'] = -1;
  dy['W'] = 0;

  while (1) {
    scanf("%d", &n);
    if (n == 0) return 0;

    fill(field[0], field[30], false);

    for (int i=0; i<n; i++) {
      scanf("%d%d", &xs[i], &ys[i]);
      field[ys[i]][xs[i]] = true;
    }
  
    scanf("%d", &m);

    int x = 10;
    int y = 10;
    int cnt = 0;
    for (int i=0; i<m; i++) {
      char d;
      int l;

      scanf(" %c %d", &d, &l);
      while (l--) {
        x += dx[d];
        y += dy[d];
        if (field[y][x]) {
          field[y][x] = false;
          cnt++;
        }
      }
    }

    if (cnt == n) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
}