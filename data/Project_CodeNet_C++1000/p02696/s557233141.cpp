#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  LL A, B, N; cin >> A >> B >> N;
  LL x = 0;
  if (N < B) x = N;
  else       x = B - 1;

  cout << (A*x)/B << endl;
}
