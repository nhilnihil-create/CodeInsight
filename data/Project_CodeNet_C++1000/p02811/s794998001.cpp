#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll k,n;
  cin >> k >> n;
  
  if(500 * k >= n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}