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

int main() {
  int s;
  cin >> s;
  int a,b,c;
  a = s / 3600;
  b = (s - a * 3600) / 60;
  c = s % 60;
  cout << a << ":" << b << ":" << c << endl;
  return 0;
}

