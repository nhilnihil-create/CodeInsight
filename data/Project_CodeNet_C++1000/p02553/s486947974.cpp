#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b,c,d; cin >> a >> b >> c >> d;
   cout << max(a*c, max(a*d, max(b*c, b*d))) << endl;
}