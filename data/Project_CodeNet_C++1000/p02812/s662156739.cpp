#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int n;
  string s;
  int ans = 0;
  cin >> n >> s;

  for(int i=0; i < n-2; i++) {
    if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}