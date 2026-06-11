#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;
typedef long long ll;

int main()
{
   int N, Q;
   cin >> N >> Q;
   dsu d(N);
   for (int i = 0; i < Q; i++)
   {
      int t, u, v;
      cin >> t >> u >> v;
      if (t == 0)
         d.merge(u, v);
      else
         cout << (d.same(u, v) ? 1 : 0) << endl;
   }

   return 0;
}
