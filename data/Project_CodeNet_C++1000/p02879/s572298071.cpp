#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b; cin >> a >> b;
  if(1<=a && a <= 9 && 1<=b && b <= 9)
    cout << a*b << endl;
  else
    cout << -1 << endl;
}