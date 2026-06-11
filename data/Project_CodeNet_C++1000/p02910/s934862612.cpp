#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int main() {
  string S; cin >> S;
  for (int i = 1; i <= S.size(); i++) {
    char c = S[i-1];
    if (i % 2) {
      if (!(c =='R' || c == 'U' || c == 'D')) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (!(c == 'L' || c == 'U' || c == 'D')) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
