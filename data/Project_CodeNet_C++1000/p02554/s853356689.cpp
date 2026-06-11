#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG
int mod = 1e9+7;

int main() {
  ll n; cin >> n;
  ll ten=1, nine=1, eight = 1;
  rep(i,n){
    ten *= 10;
    ten %= mod;
    nine *= 9;
    nine %= mod;
    eight *= 8;
    eight %= mod;
  }


  ll ans;
  ans = ten - nine*2 + eight;
  ans += mod*2;
  ans %= mod;
  cout << ans << endl;
}
