#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, K;

int main() {
  cin >> N >> K;

  cout << static_cast<int>(floor(log(N) / log(K))) + 1 << endl;

  return 0;
}
