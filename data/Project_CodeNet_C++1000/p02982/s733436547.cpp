#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cstring>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int n, d;

  cin >> n >> d;

  double m[11][11];
  memset(m, 0, sizeof m);

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < d; ++j) {
      double k;
      cin >> k;

      m[i][j] = k;
    }
  }

  int count = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      double sum = 0;
      for (int dim = 0; dim < d; ++dim) {
        sum += (m[i][dim]-m[j][dim])*(m[i][dim]-m[j][dim]);
      }
      int r = (int)sqrt(sum);
      if (r*r == (int)sum) {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
