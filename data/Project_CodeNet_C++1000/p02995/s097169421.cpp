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
  LL A, B, C, D; cin >> A >> B >> C >> D;
  --A;
  cout << (B - (B/C + B/D - B/lcm(C,D))) - (A - (A/C + A/D - A/lcm(C,D))) << endl;
}
