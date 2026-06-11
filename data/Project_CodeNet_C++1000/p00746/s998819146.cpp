#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;

int main() {
  while (true) {
    int N;
    cin >> N;
    if (N == 0) break;
    vector<int> x, y;
    x.push_back(0);
    y.push_back(0);
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    for (int i = 0; i < N-1; i++) {
      int n, d;
      cin >> n >> d;
      x.push_back(x[n]+dx[d]);
      y.push_back(y[n]+dy[d]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << x[x.size()-1] - x[0]+1 << " " << y[y.size()-1] - y[0] +1 << endl;
  }
}