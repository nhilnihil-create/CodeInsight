#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) cin >> s[i] >> t[i];
  string x;
  cin >> x;
  
  int ans = accumulate(t.begin(), t.end(), 0);
  for (int i = 0; i < n; i++) {
    if (ans >= 0) ans -= t[i];
    if (s[i] == x) break;
  }
  cout << ans << endl;
}
