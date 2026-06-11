#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int n; cin >> n;
  int ans = 0;
  for(int a = 1;a <= n; a++){
    for(int b = 1;b <= n; b++){
      for(int c = 1;c <= n; c++){
        ans += __gcd(a,__gcd(b,c));
      }
    }
  }
  cout << ans;
}