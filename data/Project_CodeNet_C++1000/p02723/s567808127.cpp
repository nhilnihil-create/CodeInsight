#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  string s;
  cin >> s;
  
  if(s.at(2) == s.at(3) && s.at(4) == s.at(5))
    cout << "Yes" << endl;
  else 
    cout << "No" << endl;
}