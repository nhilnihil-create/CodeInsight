#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int a,b,c; cin >> a >> b >> c;
  int x = a+b;
  int y = b+c;
  int z = c+a;
  cout << min(x, min(y,z)) << endl;
}