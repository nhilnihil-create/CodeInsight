#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;

    int field[5][n];
    memset(field, 0, sizeof(field));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
	cin >> field[j][i];
      }
    }

    int ans = 0;
    int memo[5][n];
    while (true) {
      bool change = false;
      for (int y = 0; y < n; y++) {
	int l, r;
	l = r = -1;
	for (int x = 0; x < 5-1; x++) {
	  while (field[x][y] != 0 && field[x][y] == field[x+1][y] && x+1 < 5) {
	    if (l == -1) {
	      l = x;
	      r = x+1;
	    }else {
	      r = x+1;
	    }
	    x++;
	  }
	  // std::cout << "(" << x << "," << y << ") = " << l << " " << r << std::endl;
	  if (r-l+1 >= 3) {
	    for (int i = l; i <= r; i++) {
	      ans += field[i][y];
	      change = true;
	      field[i][y] = 0;
	    }
	  }
	  l = r = -1;
	}
      }
      if (!change) break;

      memset(memo, 0, sizeof(memo));
      for (int x = 0; x < 5; x++) {
	int cnt = 0;
	for (int y = n-1; y >= 0; y--) {
	  cnt += field[x][y] == 0;
	  memo[x][y] = cnt;
	}
      }

      for (int x = 0; x < 5; x++) {
	for (int y = n-1; y >= 0; y--) {
	  if (field[x][y] == 0) continue;
	  if (memo[x][y] == 0) continue;
	  field[x][y+memo[x][y]] = field[x][y];
	  field[x][y] = 0;
	}
      }

    }
    std::cout << ans << std::endl;
  }
}