#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (n); i++)
int main()
{
  int n;
  cin >> n;
  if (n % 10 == 2 || n % 10 == 4 || n % 10 == 5 || n % 10 == 7 || n % 10 == 9)
  {
    cout << "hon" << endl;
  }
  else if (n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8)
  {
    cout << "pon" << endl;
  }
  else
  {
    cout << "bon" << endl;
  }
  return 0;
}