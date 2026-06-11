#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

using namespace std;

int main()
{
  uint64_t A, B, M;
  cin >> A >> B >> M;

  vector<uint64_t> a(A), b(B);
  N_TIMES(i, A) { cin >> a[i]; }
  N_TIMES(j, B) { cin >> b[j]; }

  uint64_t S = *min_element(a.begin(), a.end()) 
             + *min_element(b.begin(), b.end());

  N_TIMES(m, M) {
    uint64_t x, y, c;
    cin >> x >> y >> c;
    --x; --y;

    S = min(S, a[x] + b[y] - c);
  }

  cout << S << endl;

  return 0;
}