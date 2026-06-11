#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
#define ll long long
#define ld long double
#define ALL(x) begin(x),end(x)
     
int main() {
  ll n;
  cin >> n;
  
  map<string,ll> m;
  ll num = 0;
  rep(i,n){
    string s;
    cin >> s;
    m[s]++;
    num = max(num,m[s]);
  }
 
  for(auto i = m.begin(); i != m.end(); i++){
    if(i->second == num) cout << i->first << endl;
  }
  //rep(i,m.size()) cout << m[i] << endl;
}
