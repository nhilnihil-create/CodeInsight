#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll h,n;
  cin >> h >> n;
  vector<ll> sp(n);
  rep(i, n)
    cin >> sp.at(i);
  
  ll sum=0;
  rep(i, n)
    sum += sp.at(i);
  
  if(sum >= h)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
    
}