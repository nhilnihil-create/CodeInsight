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
  ll H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if ((i < B && j < A) || (B <= i && A <= j)) {
        cout << 0;
      } else {
        cout << 1;
      }
    }
    cout << endl;
  }
  return 0;
}