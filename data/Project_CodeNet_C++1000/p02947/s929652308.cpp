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
  ll N;
  cin >> N;
  vector<string> s(N);
  map<string, int> m;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
    if (m[s[i]] != 0) {
      ans += m[s[i]];
    }
    m[s[i]]++;
  }
  cout << ans << endl;
  return 0;
}