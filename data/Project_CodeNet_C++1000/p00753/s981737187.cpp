#define _USE_MATH_DEFINES
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <math.h>
#include <numeric>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <set>
#include <memory.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <map>
#include <cassert>
#include <time.h>
#include <ctime>

using namespace std;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int , P> PP;
typedef pair<int, string> Ps;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF = 1 << 30;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;
const int CLK = CLOCKS_PER_SEC;

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)

bool prime[1000000];

int main()

{
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for(int i = 2; i * i < 1000000; i++){
    if(prime[i]){
      for(int j = 2; j * i < 1000000; j++){
	prime[i*j] = false;
      }
    }
  }
  int n;
  while(cin >> n && n){
    int cnt = 0;
    for(int i = n + 1; i <= 2 * n; i++){
      if(prime[i]) cnt++;
    }
    cout <<cnt << endl;
  }

  return 0;
}