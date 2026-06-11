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
   int n;
   cin >> n;
   multiset<int> s;
   for (int i = 0; i < n; i++)
   {
      int a;
      cin >> a;
      s.insert(a);
   }
   int ans = 0;
   while (!s.empty())
   {
      int a = *(s.begin());
      if (s.count(a) == 1)
         ans++;
      for (int i = 1; i * a <= 1000000; i++)
      {
         s.erase(i * a);
      }
   }
   cout << ans << endl;
}