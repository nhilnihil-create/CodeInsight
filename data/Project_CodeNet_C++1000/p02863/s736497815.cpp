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
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }

  vector<int> cur0(T + 1);
  vector<int> next0(T + 1);
  vector<int> cur1(T + 1);
  vector<int> next1(T + 1);

  // Init
  {
    int a = A[0];
    int b = B[0];
    fill(cur0.begin(), cur0.end(), -1);
    fill(cur1.begin(), cur1.end(), -1);
    cur0[0] = 0;
    if (a <= T) cur0[a] = b;
    cur1[1] = b;
  }

  // Iterate
  for (int i = 1; i < N; ++i) {
    int a = A[i];
    int b = B[i];
    fill(next0.begin(), next0.end(), -1);
    fill(next1.begin(), next1.end(), -1);
    
    // process cur0
    for (int t = 0; t <= T; ++t) {
      if (cur0[t] >= 0) {
	next0[t] = max(next0[t], cur0[t]);
	if (t + a <= T) next0[t + a] = max(next0[t + a], cur0[t] + b);
	if (t + 1 <= T) next1[t + 1] = max(next1[t + 1], cur0[t] + b);
      }
    }

    // process cur1
    for (int t = 0; t <= T; ++t) {
      if (cur1[t] >= 0) {
	next1[t] = max(next1[t], cur1[t]);
	if (t + a <= T) next1[t + a] = max(next1[t + a], cur1[t] + b);
      }
    }
    
    swap(cur0, next0);
    swap(cur1, next1);
  }

  // Terminate
  int mx = 0;
  for (int t = 0; t <= T; ++t) {
    mx = max(mx, cur1[t]);
  }
  cout << mx << endl;
  
  return 0;
}
