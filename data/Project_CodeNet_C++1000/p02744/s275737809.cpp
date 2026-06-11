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

int N;

void dfs(const string& S, int v, int k) {
  if (k ==  N) {
    cout << S << endl;
    return;
  }

  ++k;
  for (int i = 0; i <= v; ++i) {
    char c = 'a' + i;
    dfs(S + c, v, k);
  }
  ++v;
  char c = 'a' + v;
  dfs(S + c, v, k);
}

int main() {
  cin >> N;
  dfs("a", 0, 1);
}
