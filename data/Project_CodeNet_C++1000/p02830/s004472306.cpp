#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  string S,T;
  cin >> S >> T;
  string ans = "";
  for (int i = 0; i < N; i++) {
    ans += S[i];
    ans += T[i];
  }
  cout << ans << endl;
  return 0;
}