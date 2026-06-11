#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main()
{
   long long int n, d, a;
   cin >> n >> d >> a;
   vector<pair<long long int, long long int>> v;
   for (int i = 0; i < n; i++)
   {
      long long int x, h;
      cin >> x >> h;
      v.push_back(make_pair(x, h));
   }
   sort(v.begin(), v.end());
   long long int ans = 0;
   long long int cnt[200000] = {};
   for (int i = 0; i < n; i++)
   {
      if (i > 0)
         cnt[i] += cnt[i - 1];
      long long int x = v[i].first;
      long long int h = v[i].second;
      long long int need = h / a;
      if (h % a > 0)
         need++;
      need -= cnt[i];
      if (need <= 0)
         continue;
      cnt[i] += need;
      int idx = lower_bound(v.begin(), v.end(), make_pair(x + 2 * d + 1, (long long int)0)) - v.begin();
      if (idx != v.size())
         cnt[idx] -= need;
      ans += need;
   }
   cout << ans << endl;
}