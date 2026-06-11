#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef map<string, int> M;
int main(void) {
  int n;
  cin >> n;
  M m;
  string s;
  vector<int> t(n);
  rep(i, n) {
    cin >> s >> t[i];
    m[s] = i;
  }
  string x;
  cin >> x;
  int ans = 0;
  for(int i = m[x] + 1; i < n; i++) {
    ans += t[i];
  }
  cout << ans << endl;
  return 0;
}