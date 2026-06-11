#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = ll(1e9 + 7);
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  int TT = 1;
  // cin >> TT;
  while (TT--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    ll b = stoll(s.substr(0,s.find('.')));
    ll c = stoll(s.substr(s.find('.')+1));
    cout << n*b + (n*c)/100 << endl;


  }
}
