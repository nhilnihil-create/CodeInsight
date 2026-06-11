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

bool compare(int h1, int w1, int h2, int w2) {
  return ((h1*h1+w1*w1 < h2*h2+w2*w2) ||
	  (h1*h1+w1*w1 == h2*h2+w2*w2 && h1 < h2));
}

int main() {
  int h,w;
  while(true) {
    cin >> h >> w;
    if (h == 0 && w == 0) break;

    int ansh = 1000, answ = 1000;
    for (int th = 1; th <= 150; th++) {
      for (int tw = th+1; tw <= 150; tw++) {
	int dia = th*th+tw*tw;

	if (compare(h, w, th, tw) && compare(th, tw, ansh, answ)) {
	  ansh = th;
	  answ = tw;
	}
      }
    }

    std::cout << ansh << " " << answ << std::endl;
  }
}