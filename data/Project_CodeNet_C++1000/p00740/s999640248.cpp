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
  int n, p;
  while (true) {
    cin >> n >> p;
    if (n == 0 && p == 0) break;

    int a[n], wan = p;
    memset(a, 0, sizeof(a));
    int i = 0;
    while (true) {
      if (wan == 0) {
	wan = a[i];
	a[i] = 0;
      }else {
	a[i]++;
	wan--;
	if (a[i] == p) {
	  std::cout << i << std::endl;
	  break;
	}
      }
      i = (i+1)%n;
    }
  }
}