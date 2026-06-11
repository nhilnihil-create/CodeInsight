#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    ans += L + i - 1;
  }
  if(L > 0) {
    ans -= L;
  }
  else if(-L + 1 > N) {
    ans -= L + N - 1;
  }
  cout << ans << endl;
}
