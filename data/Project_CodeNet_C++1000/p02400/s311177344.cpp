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
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (double)(acos(-1))

int main() {
  double r;
  cin >> r;
  cout << fixed;
  cout << setprecision(8) <<(double) r * r * PI << " " <<(double) 2 * r * PI << endl;
  //cout <<(double) r * r * PI << " " <<(double) 2 * r * PI << endl;
  return 0;
}

