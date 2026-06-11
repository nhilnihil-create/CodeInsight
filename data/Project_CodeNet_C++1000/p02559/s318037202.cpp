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
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;
typedef long long ll;

int main()
{
   int N, Q;
   cin >> N >> Q;
   vector<int> a(N);
   fenwick_tree<ll> fw(N);
   for (int i = 0; i < N; i++)
   {
      cin >> a[i];
      fw.add(i, a[i]);
   }
   for (int i = 0; i < Q; i++)
   {
      int op, q, x;
      cin >> op >> q >> x;
      if (op == 0)
         fw.add(q, x);
      else
         cout << fw.sum(q, x) << endl;
   }

   return 0;
}
