#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  vector<string>  S = {"Sunny", "Cloudy", "Rainy"};

  string s; cin >> s;
  if(s==S[0]) cout << S[1] << endl;
  if(s==S[1]) cout << S[2] << endl;
  if(s==S[2]) cout << S[0] << endl;
}