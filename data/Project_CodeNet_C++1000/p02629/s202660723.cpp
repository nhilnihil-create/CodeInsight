#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  ll N;
  cin >> N;
  string ans;
  while (N > 0) {
    int res = N % 26;
    if (res == 0) {
      res = 26;
    }
    ans += (char)('a' + res - 1);
    N = (N - res) / 26;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}