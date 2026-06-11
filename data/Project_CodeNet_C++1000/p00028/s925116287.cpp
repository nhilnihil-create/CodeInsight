#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<cmath>
#include<memory>
#include<array>

using namespace std;

int main()
{
  array<int,101> a{};
  int d;

  while ( cin >> d )
    ++a[d];

  int mx = 0;

  for ( auto i = 1; i <= 100; ++i )
    if ( mx < a[i] ) mx = a[i];

  for ( auto i = 1; i <= 100; ++i )
    if ( a[i] == mx ) cout << i << endl;

  return 0;
}