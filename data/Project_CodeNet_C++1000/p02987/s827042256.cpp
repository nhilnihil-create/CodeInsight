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
  bool cond1 = (S[0] == S[1]) && (S[2] == S[3]) && (S[0] != S[2]);
  bool cond2 = (S[0] == S[2]) && (S[1] == S[3]) && (S[0] != S[1]);
  bool cond3 = (S[0] == S[3]) && (S[1] == S[2]) && (S[0] != S[1]);
  if (cond1 || cond2 || cond3)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}