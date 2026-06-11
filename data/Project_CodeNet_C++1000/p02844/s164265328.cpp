#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for (int i = 0; i < (n); i++)


int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  // 3桁の数字なので1000
  rep(i,1000) {
    string t;
    int x = i;
    // 文字列で3桁の数を作成
    rep(j,3) {
      // '0'+とすることで先頭に0も付けられる
      t += '0'+x%10;
      x /= 10;
    }
    int ti = 0;
    // 連続する数なため
    rep(j,n) {
      if (s[j] == t[ti]) {
        ++ti;
        if (ti == 3) {
          break;
        }
      }
    }
    if (ti == 3) {
      ans ++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
