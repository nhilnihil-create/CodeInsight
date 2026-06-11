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
  map<string, int> count;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    count[S]++;
  }
  
  int mx = 0;
  for (auto x : count) {
    //string s = x.first;
    int cnt = x.second;
    mx = max(mx, cnt);
  }

  for (auto x : count) {
    string s = x.first;
    int cnt = x.second;
    if (cnt == mx) {
      cout << s << endl;
    }
  }
  
  return 0;
}
