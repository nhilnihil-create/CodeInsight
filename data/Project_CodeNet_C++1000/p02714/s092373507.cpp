#include<bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll n;
  string s;
  cin >> n >> s;
  ll r = 0, g = 0; 
  rep(i,n) {
    if (s[i]=='R') r++;
    if (s[i]=='G') g++;
  }
  ll b = n-r-g;
  ll a = 0;
  rep(i,n) {
    for (ll j=i+1; j<(n); j++) {
      ll k = 2*j-i;
      if ((k < n) && (s[i] != s[j]) && (s[j] != s[k]) && (s[k] != s[i])) a++;
    }
  }
  cout << r*g*b-a << endl;
}