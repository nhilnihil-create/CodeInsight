#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  string s;
  rep(i,n) cin >> s;
  int j = n - 1, tmp = n - 1, ans = 0,end;
  for(int i = 0;i < n - 1;i++) {
    if(s[i] == 'W') {
      end = 0;
      for(j = tmp;j >= 1 + i;j--) {
        if(s[j] == 'R') {
          swap(s[i],s[j]);
          ans++;
          end = 1;
        }
        if(end) break;
      }
    tmp = j;
    }
    if(i + 1 == j) break;
  }
  cout << ans << endl;
}