#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class CBtree
{
public:
  vector<int> a;
  int solve();
};

int CBtree::solve()
{
  int n, x;
  cin >> n;

  a.push_back( 0 );
  
  for ( auto i = 0; i < n; ++i )
    {
      cin >> x;
      a.push_back( x );
    }

  for ( auto i = 1; i <= n; ++i )
    {
      cout << "node " << i << ": ";
      cout << "key = " << a[i] << ", ";
      if ( i / 2 > 0 )
        cout << "parent key = " << a[i/2] << ", ";
      if ( i * 2 <= n )
        cout << "left key = " << a[i * 2] << ", ";
      if ( i * 2 + 1 <= n )
        cout << "right key = " << a[i * 2 + 1] << ", ";
      cout << endl;
    }
  
  return 0;
}

int main()
{
  CBtree c;

  c.solve();

  return 0;
}