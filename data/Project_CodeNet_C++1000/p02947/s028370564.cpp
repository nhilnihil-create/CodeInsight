#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  map<string, int> m;

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ans += m[s];
    m[s]++;
  }
  cout << ans << endl;
}