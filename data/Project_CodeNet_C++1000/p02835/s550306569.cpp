#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int A1, A2, A3;

int main() {
  cin >> A1 >> A2 >> A3;
  cout << (A1 + A2 + A3 >= 22 ? "bust" : "win") << endl;

  return 0;
}
