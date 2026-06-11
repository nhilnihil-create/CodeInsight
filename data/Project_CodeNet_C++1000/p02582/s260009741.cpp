//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  int cnt = 0;
  for (char c : s) {
    if (c == 'S') {
      cnt = 0;
    } else {
      ++cnt;
      ans = max(ans, cnt);
    }
  } 
  cout << ans << '\n';
  return 0;
}
