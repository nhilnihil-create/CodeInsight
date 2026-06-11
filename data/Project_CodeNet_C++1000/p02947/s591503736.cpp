#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) cin >> s[i];
  for (int i = 0; i < N; i++) {
    sort(s[i].begin(),s[i].end());
  }
  sort(s.begin(),s.end());
  ll ans = 0;
  ll streak = 1;
  for (int i = 1; i < N; i++) {
    if (s[i-1] == s[i]) {
      streak++;
    } else {
      ans += (streak * (streak - 1)) / 2;
      streak = 1;
    }
  }
  ans += (streak * (streak - 1)) / 2;
  cout << ans << endl;
  return 0;
}