#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string S;
  cin >> S;
  set<char> odd = {'R', 'U', 'D'};
  set<char> even = {'L', 'U', 'D'};
  bool succ = true;
  for (int i = 0; i < S.length(); i++) {
    if (i % 2 == 0 && odd.find(S[i]) == odd.end()) {
      succ = false;
      break;
    } else if (i % 2 == 1 && even.find(S[i]) == even.end()) {
      succ = false;
      break;
    }
  }
  string ans = (succ) ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}