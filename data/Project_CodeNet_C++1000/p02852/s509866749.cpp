#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  reverse(S.begin(), S.end());

  vector<int> back(N + 1);
  int prev = 0;
  for (int i = 1; i <= N; ++i) {
    if (S[i] == '0') prev = i;
    else back[i] = prev;
  }
  
  vector<int> steps;
  int cur = 0;
  while (true) {
    int next = cur + M;
    if (next >= N) {
      next = N;
      steps.push_back(next - cur);
      break;
    }
    if (S[next] == '1') {
      // while (S[next] == '1') {
      // 	--next;
      // }
      next = back[next];
      if (next == cur) {
	cout << -1 << endl;
	return 0;
      }
    }
    steps.push_back(next - cur);
    cur = next;
  }
  
  reverse(steps.begin(), steps.end());
  for (auto step : steps) {
    cout << step << " ";
  }
  cout << endl;
  
  return 0;
}
