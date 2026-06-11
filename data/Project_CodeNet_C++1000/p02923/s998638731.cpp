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
  int Ai; cin >> Ai;
  int vmax = 0;
  int cnt = 0;
  for (int i = 1; i < N; ++i) {
    int A; cin >> A;
    if (Ai >= A) {
      Ai = A; ++cnt;
    } else {
      Ai = A; cnt = 0;
    }
    vmax = max(vmax, cnt);
  }
  cout << vmax << endl;
}
