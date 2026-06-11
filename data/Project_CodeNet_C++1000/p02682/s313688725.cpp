#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
#include <climits>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))

int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;

  if (K < A)
  {
    cout << K << endl;
  }
  else if (A <= K && K < A+B)
  {
    cout << A << endl;
  }
  else if (A+B <= K)
  {
    cout << A - (K-A-B) << endl;
  }

  return 0;
}