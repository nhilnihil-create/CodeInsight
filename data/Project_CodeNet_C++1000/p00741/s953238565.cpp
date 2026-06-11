#include <algorithm>
#include <vector>
#include <cfloat>
#include <string>
#include <cmath>
#include <set>
#include <cstdlib>
#include <map>
#include <ctime>
#include <iomanip>
#include <functional>
#include <deque>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <stack>
#include <climits>
#include <sys/time.h>
#include <cctype>

using namespace std;

typedef long long ll;

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    bool field[w][h];
    memset(field, false, sizeof(field));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	int t;
	cin >> t;
	if (t == 0) {
	  field[j][i] = false;
	}else {
	  field[j][i] = true;
	}
      }
    }

    int cnt = 0;
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	if (field[j][i]) {
	  stack<int> st;
	  st.push(j);
	  st.push(i);
	  field[j][i] = false;
	  while (!st.empty()) {
	    int y = st.top(); st.pop();
	    int x = st.top(); st.pop();

	    for (int p = 0; p < 8; p++) {
	      int nx = x+dx[p];
	      int ny = y+dy[p];

	      if (nx < 0 || ny < 0 ||
		  nx >= w || ny >= h ||
		  !field[nx][ny]) {
		continue;
	      }
	      st.push(nx);
	      st.push(ny);
	      field[nx][ny] = false;
	    }
	  }
	  cnt++;
	}
      }
    }

    std::cout << cnt << std::endl;
  }
}