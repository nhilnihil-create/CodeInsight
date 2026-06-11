#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

bool get[100];
int gx[100];
int gy[100];
int dx[200];
int dy[200];

int main() {
  dx['W'] = -1;
  dx['S'] = 0;
  dx['N'] = 0;
  dx['E'] = 1;
  dy['W'] = 0;
  dy['S'] = -1;
  dy['N'] = 1;
  dy['E'] = 0;
  int n;
  while (scanf("%d", &n), n) {
    MEMSET(get, false);
    REP(i, n) {
      scanf("%d %d", &gx[i], &gy[i]);
    }
    int m;
    scanf("%d", &m);
    int total = 0;
    int x = 10;
    int y = 10;
    REP(i, m) {
      char c;
      int cnt;
      scanf(" %c %d", &c, &cnt);
      REP(j, cnt) {
        x += dx[(int)c];
        y += dy[(int)c];
        REP(k, n) {
          if (get[k]) { continue; }
          if (x == gx[k] && y == gy[k]) { get[k] = true; total++; }
        }
      }
    }
    if (n == total) { puts("Yes"); }
    else { puts("No"); }
  }
}