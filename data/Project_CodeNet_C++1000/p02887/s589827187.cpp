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
  int N; cin >> N;
  string S; cin >> S;
  int cnt = 0;
  for (int i = 1; i < N; ++i) {
    if (S[i-1] != S[i]) ++cnt;
  }
  cout << cnt + 1 << endl;
}
