#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define mod 1000000007
using namespace std;

int main() {
  long long int n;
  string s;
  cin >> n >> s;

  long long int ans = 1, num = 0;
  rep(i, 2*n){
    if (s[i] == 'W' ^ num % 2 == 0) num++;
      else{
        ans *= num;
        ans %= mod;
        num--;
      }
    }
    if (num != 0) ans = 0;
    rep(i, n){
      ans *= (i + 1);
      ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
