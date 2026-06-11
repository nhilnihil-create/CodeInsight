#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  ll a,b,c,d; cin >> a >> b >> c >> d;
  ll all = b - a + 1;
  a--;
  ll c_diff = b/c - a/c;
  ll d_diff = b/d - a/d;
  ll cdgcd = c*d/gcd(c,d);
  ll gcd_diff = b/cdgcd - a/cdgcd;
  cout << all - c_diff - d_diff + gcd_diff << endl;
}