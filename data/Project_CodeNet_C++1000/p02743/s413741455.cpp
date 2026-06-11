#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define big ((ll)(1e9) + 7)

ll max(ll a, ll b)
{
  if (a > b)
  {
    return a;
  }
  return b;
}

int main()
{
  ll a,b,c;
  cin >> a >> b >> c;
  ll pow = c-a-b;
  if(4*a*b < pow*pow && pow > 0 )
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
