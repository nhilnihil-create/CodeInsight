#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;
  int s1 = 0;
  int s2 = accumulate(vec.begin(), vec.end(), 0);
  int ans = s2 - s1;
  for (int i = 0; i < n; ++i) {
    s1 += vec[i];
    s2 -= vec[i];
    int tmp = abs(s2 - s1);
    ans = min(tmp, ans);
  }
  cout << ans << endl;
}