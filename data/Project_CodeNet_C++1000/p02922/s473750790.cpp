#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A,B;
  cin >> A >> B;
  int res = 1;
  int ans = 0;
  while (res < B) {
    ans++;
    res += A-1;
  }
  cout << ans << endl;
  return 0;
}