#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b,c; cin >> a >> b >> c;
  
  cout << max(c-(a-b), (ll)0) << endl;
}
