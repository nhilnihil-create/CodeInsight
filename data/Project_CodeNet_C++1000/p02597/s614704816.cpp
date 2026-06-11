#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define MOD 1000000007

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  rep(i,n) {
    if (s[i] == 'W') cnt++;
  }
  int ans = 0;
  rep(i,n-cnt) {
    if (s[i] == 'W') ans++;
  }
  cout << ans << endl;
  return 0;
}