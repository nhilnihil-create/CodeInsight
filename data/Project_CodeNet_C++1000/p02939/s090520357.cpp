#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_set>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  string S; cin >> S;
  int N = S.size();
  int cnt1 = 0, cnt2 = 0;
  string prev;
  for (int i = 0; i < N;) {
    string str; str = S[i]; ++i;
    while (str == prev && i < N) {
      str += S[i];
      ++i;
    }
    if (str != prev) {
      ++cnt1;
    }
    prev = str;
  }

  prev = "";
  for (int i = N-1; i >= 0;) {
    string str; str = S[i]; --i;
    while (str == prev && i >= 0) {
      str += S[i];
      --i;
    }
    if (str != prev) {
      ++cnt2;
    }
    prev = str;
  }
  cout << max(cnt1, cnt2) << endl;
}
