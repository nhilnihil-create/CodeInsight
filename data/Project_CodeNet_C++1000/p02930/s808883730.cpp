#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>

using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int b = 0; b < 9; ++b) {
	int x = (i>>b) & 1;
	int y = (j>>b) & 1;
	if (x != y) {
	  cout << b + 1 << " ";
	  break;
	}
      }
    }
    cout << endl;
  }
  
  return 0;
}
