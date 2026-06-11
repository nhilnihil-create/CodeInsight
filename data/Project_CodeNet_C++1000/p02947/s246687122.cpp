#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
int main() {
  ll N, ans{};
  cin >> N;
  unordered_map<string, int> m;
  string S;
  while (cin >> S) {
    sort(begin(S), end(S));
    ans += m[S]++;
  }
  cout << ans << endl;
}
