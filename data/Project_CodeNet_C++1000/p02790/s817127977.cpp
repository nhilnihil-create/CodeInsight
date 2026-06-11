#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int a,b;
  cin >> a >> b;
  int c = min(a,b);
  int d = max(a,b);
  string ans = string(d,(c + '0'));
  cout << ans << endl;
  return 0;
}