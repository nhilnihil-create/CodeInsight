#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n;
  string s,t;
  cin >> n >> s >> t;
  vector<char> ans(2*n);
  rep(i, n){
    ans.at(2*i) = s.at(i);
    ans.at(2*i+1) = t.at(i);
  }
  rep(i, 2*n)
    cout << ans.at(i);
  cout << endl;
}