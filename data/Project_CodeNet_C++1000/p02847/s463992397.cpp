#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  string tmp[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
  int ans = 1;
  for (int i = 6; i >= 0; i--) {
    if (tmp[i] == S) {
      cout << ans << endl;
    }
    ans++;
  }
  return 0;
}