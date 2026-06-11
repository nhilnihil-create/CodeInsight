#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  int mod;
  string ans = " ";

  while (n!=0) {
    n--;
    mod = n % 26;
    char c = ('a' + mod);
    ans = c + ans;
    n /= 26;
    //cout << mod << " " << c << " " << n << endl;
  }
  cout << ans << endl;
}  